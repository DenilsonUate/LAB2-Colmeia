#include <iostream> 
// Em C usaríamos: #include <stdio.h>
// Em C++ usamos a biblioteca iostream que permite entrada e saída com cin e cout

#include <string>
// Em C normalmente trabalharíamos com texto usando arrays de char.
// Em C++ existe o tipo string que facilita trabalhar com texto.

#include <fstream>
// Em C manipular ficheiros usa FILE* e funções como fopen e fprintf.
// Em C++ usamos fstream com objetos como ofstream e ifstream.

#include <limits>
// Biblioteca usada para limpar erros de entrada do teclado.

#include <cctype>
// Biblioteca usada para verificar caracteres (isdigit).

using namespace std;
// Em C não existe namespace.
// Em C++ usamos namespace para evitar escrever std:: antes de cout, cin, string, etc.

// ==============================
// FUNÇÃO DE VALIDAÇÃO
// ==============================

bool soNumeros(const string& texto)
{
    // Em C não temos strings nativas como em C++.
    // Aqui usamos o tipo string e verificamos carácter por carácter.

    if(texto.empty())
        return false;

    for(char c : texto)
    {
        // isdigit é função da biblioteca cctype (C++)
        // Em C seria necessário lógica manual com ASCII.
        if(!isdigit(c))
            return false;
    }

    return true;
}

int main()
{
    cout << "Sistema de Pedidos do Restaurante" << endl;
    cout << "Programa iniciado com sucesso!" << endl;

    // cout é usado em C++ para saída de dados.
    // Em C usaríamos printf.

    string pratos[50];
    float precos[50];
    int pedidos_mesa[50] = {0};

    // Em C usaríamos arrays normais ou estruturas.
    // Em C++ podemos usar string diretamente.

    int total_pratos = 0;

    // ==============================
    // LEITURA DO MENU
    // ==============================

    ifstream menu("menu.txt");

    // ifstream é usado em C++ para leitura de ficheiros.
    // Em C usaríamos FILE* e fopen.

    if(!menu)
    {
        cout << "Erro ao abrir menu.txt" << endl;
        return 1;
    }

    string nome;
    float preco;

    while(menu >> nome >> preco)
    {
        // Em C usaríamos fscanf.
        // Em C++ usamos o operador >> para ler do ficheiro.

        pratos[total_pratos] = nome;
        precos[total_pratos] = preco;

        total_pratos++;
    }

    menu.close();

    // ==============================
    // MOSTRAR MENU
    // ==============================

    cout << "\n===== MENU =====" << endl;

    for(int i = 0; i < total_pratos; i++)
    {
        cout << i+1 << " - " << pratos[i]
             << " : " << precos[i] << " MZN" << endl;

        // Em C usaríamos printf com %d, %s, %.2f.
    }

    // ==============================
    // PEDIDOS
    // ==============================

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while(true)
    {
        string entrada;

        cout << "\nDigite numero do prato (0 para finalizar): ";
        getline(cin, entrada);

        // Em C não existe getline para strings como em C++.
        // Aqui usamos getline para ler linha inteira.

        if(!soNumeros(entrada))
        {
            cout << "Erro: Apenas numeros sem espacos!" << endl;
            continue;
        }

        int opcao = stoi(entrada);

        // stoi é função do C++ para converter string em inteiro.
        // Em C usaríamos atoi.

        if(opcao == 0)
            break;

        if(opcao < 1 || opcao > total_pratos)
        {
            cout << "Prato invalido!" << endl;
            continue;
        }

        cout << "Quantidade: ";
        getline(cin, entrada);

        if(!soNumeros(entrada))
        {
            cout << "Erro: Quantidade deve ser numero positivo!" << endl;
            continue;
        }

        int quantidade = stoi(entrada);

        if(quantidade <= 0)
        {
            cout << "Quantidade invalida!" << endl;
            continue;
        }

        pedidos_mesa[opcao-1] += quantidade;

        cout << "Pedido adicionado com sucesso!" << endl;
    }

    // ==============================
    // CÁLCULO
    // ==============================

    float subtotal = 0;

    for(int i = 0; i < total_pratos; i++)
    {
        subtotal += pedidos_mesa[i] * precos[i];

        // Operações matemáticas são iguais em C e C++.
    }

    float iva = subtotal * 0.16;
    float total = subtotal + iva;

    cout << "\nSubtotal: " << subtotal << " MZN" << endl;
    cout << "IVA (16%): " << iva << " MZN" << endl;
    cout << "Total: " << total << " MZN" << endl;

    // ==============================
    // ESCRITA DO FICHEIRO
    // ==============================

    ofstream conta("conta_mesa_1.txt");

    // ofstream é usado em C++ para escrever ficheiros.
    // Em C usaríamos fopen com modo "w".

    conta << "===== CONTA DA MESA =====" << endl;

    for(int i = 0; i < total_pratos; i++)
    {
        if(pedidos_mesa[i] > 0)
        {
            conta << pratos[i] << " x "
                  << pedidos_mesa[i] << " = "
                  << pedidos_mesa[i] * precos[i]
                  << " MZN" << endl;
        }
    }

    conta << "\nSubtotal: " << subtotal << " MZN" << endl;
    conta << "IVA (16%): " << iva << " MZN" << endl;
    conta << "Total: " << total << " MZN" << endl;

    conta.close();

    cout << "\nConta gerada com sucesso!" << endl;

    return 0;
}
