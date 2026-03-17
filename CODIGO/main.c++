#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Sistema de Pedidos do Restaurante" << endl;
    cout << "Programa iniciado com sucesso!" << endl;

    string pratos[15] = {
        "Frango Grelhado",
        "Arroz com Caril",
        "Hamburguer",
        "Pizza",
        "Batatas Fritas",
        "Sumo Natural",
        "Refrigerante",
        "Cafe",
        "Bolo de Chocolate",
        "Sandes de Frango"
    };

    float precos[15] = {
        350,250,180,400,120,90,80,50,150,160
    };

    int pedidos_mesa[15] = {0};

    int total_pratos = 10;

    cout << "\n===== MENU =====" << endl;

    for(int i = 0; i < total_pratos; i++)
    {
        cout << i + 1 << " - " << pratos[i] << " : "
             << precos[i] << " MZN" << endl;
    }

    return 0;
}
