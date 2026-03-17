# LAB2-Colmeia
Menu de restaurante/cafe
README - Sistema de Pedidos do Restaurante
Descrição
Este é um programa simples em C++ para registrar pedidos de um restaurante. O usuário pode selecionar pratos do menu, especificar quantidades e o sistema calcula automaticamente o subtotal, IVA (16%) e o valor total, gerando um arquivo de conta.

Funcionalidades
Exibição do menu com 10 pratos e seus respectivos preços

Registro de pedidos por mesa

Cálculo automático de:

Subtotal

IVA (16%)

Total a pagar

Geração de arquivo de texto com a conta detalhada

Como usar
Execute o programa

Digite o número do prato desejado (1-10)

Digite a quantidade

Repita os passos 2-3 para adicionar mais itens

Digite 0 para finalizar o pedido

O programa exibirá o total e criará um arquivo conta_mesa_1.txt

Menu de pratos
Nº	Prato	Preço (MZN)
1	Frango Grelhado	350
2	Arroz com Caril	250
3	Hamburguer	180
4	Pizza	400
5	Batatas Fritas	120
6	Sumo Natural	90
7	Refrigerante	80
8	Cafe	50
9	Bolo de Chocolate	150
10	Sandes de Frango	160
Arquivo gerado
O programa cria automaticamente o arquivo conta_mesa_1.txt contendo:

Lista detalhada dos itens pedidos

Quantidades e preços individuais

Subtotal

Valor do IVA (16%)

Total final

Requisitos
Compilador C++ (g++, Visual Studio, etc.)

Sistema operacional: Windows, Linux ou MacOS

Como compilar
bash
g++ restaurante.cpp -o restaurante
./restaurante
