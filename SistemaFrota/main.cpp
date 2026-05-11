#include <iostream>
#include <string>
#include <iomanip> // Para formatar as casas decimais

using namespace std;

// 1. ABSTRAÇÃO: Classe base que define o molde para qualquer veículo
class Veiculo
{
protected:
    string modelo;
    double distanciaKm;

public:
    Veiculo(string mod, double dist) : modelo(mod), distanciaKm(dist) {}

    // Destrutor Virtual: Garante a limpeza correta de memória das classes filhas
    virtual ~Veiculo() {}

    string getModelo() const
    {
        return modelo;
    }

    // Função Virtual Pura: Torna a classe abstrata
    virtual double calcularCustoViagem() = 0;
};

// 2. HERANÇA: Carro estende as funcionalidades de Veiculo
class Carro : public Veiculo
{
public:
    Carro(string mod, double dist) : Veiculo(mod, dist) {}

    // 3. POLIMORFISMO: Implementação específica para carros
    double calcularCustoViagem() override
    {
        return distanciaKm * 0.95; // Custo fixo por KM
    }
};

// 2. HERANÇA: Caminhao estende Veiculo e adiciona novos atributos
class Caminhao : public Veiculo
{
private:
    double cargaToneladas;

public:
    Caminhao(string mod, double dist, double carga)
        : Veiculo(mod, dist), cargaToneladas(carga) {}

    // 3. POLIMORFISMO: Cálculo que considera o peso da carga
    double calcularCustoViagem() override
    {
        return (distanciaKm * 3.80) + (cargaToneladas * 60.0);
    }
};

// FUNÇÃO AUXILIAR PARA DEMONSTRAR O POLIMORFISMO
// Recebe um ponteiro para a classe base (Veiculo), mas executa o código da classe filha.
void exibirRelatorio(Veiculo* v)
{
    cout << "Veiculo: " << v->getModelo()
         << " | Custo Total: R$ " << v->calcularCustoViagem() << endl;
}

int main()
{
    double distCarro, distCaminhao, pesoCarga;

    cout << "### Sistema de Gestao de Frota POO ###" << endl;

    // ENTRADA DE DADOS
    cout << "Distancia percorrida pelo Carro (km): ";
    cin >> distCarro;

    cout << "Distancia percorrida pelo Caminhao (km): ";
    cin >> distCaminhao;
    cout << "Peso da carga do Caminhao (toneladas): ";
    cin >> pesoCarga;

    // Instanciação manual dos objetos usando ponteiros
    Veiculo* meuCarro = new Carro("Sedan Executivo", distCarro);
    Veiculo* meuCaminhao = new Caminhao("Volvo FH", distCaminhao, pesoCarga);

    cout << fixed << setprecision(2);
    cout << "\n--- Relatorio de Custos de Viagem ---" << endl;

    // 4. APLICAÇÃO DO POLIMORFISMO
    // A mesma função comporta-se de maneira diferente consoante o objeto passado
    exibirRelatorio(meuCarro);
    exibirRelatorio(meuCaminhao);

    // Libertação manual de memória (Gestão de Recursos em C++)
    delete meuCarro;
    delete meuCaminhao;

    return 0;
}
