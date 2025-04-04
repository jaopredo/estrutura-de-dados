#include "WaitingQueue.h"
#include <iostream>

using namespace WaitingQueueTAD;
using namespace std;

int main() {
    WaitingQueue* waiting_queue = createQueue();  // Criando a lista

    Client cliente_1 = Client();
    cliente_1.name = "Seu Genesio";
    cliente_1.priority = 1;

    Client cliente_2 = Client();
    cliente_2.name = "Camacho";
    cliente_2.priority = 1;

    Client cliente_3 = Client();
    cliente_3.name = "Paulo Sad";
    cliente_3.priority = 1;

    Client cliente_4 = Client();
    cliente_4.name = "Joao Pedro";
    cliente_4.priority = 0;

    Client cliente_5 = Client();
    cliente_5.name = "Thalis";
    cliente_5.priority = 0;

    Client cliente_6 = Client();
    cliente_6.name = "Alex";
    cliente_6.priority = 0;

    Client cliente_7 = Client();
    cliente_7.name = "Paulo César";
    cliente_7.priority = 1;

    Client cliente_8 = Client();
    cliente_8.name = "Sonia";
    cliente_8.priority = 1;

    enqueue(waiting_queue, cliente_1);
    enqueue(waiting_queue, cliente_2);
    enqueue(waiting_queue, cliente_3);
    enqueue(waiting_queue, cliente_4);
    enqueue(waiting_queue, cliente_5);
    enqueue(waiting_queue, cliente_6);
    enqueue(waiting_queue, cliente_7);
    enqueue(waiting_queue, cliente_8);

    // Pegando a ordem da fila
    cout << "===============" << endl;
    cout << "Pegando ordem da lista" << endl;

    int numClients = waiting_queue->size;
    Client* client_order = getQueueOrder(waiting_queue, &numClients);

    for (int i = 0; i < numClients; i++) {
        cout << (client_order + i)->name << ", ";
    }
    cout << endl;

    delete[] client_order;

    // Deletando um Geral
    cout << "===============" << endl;
    cout << "Deletei o Alex e o Seu Genesio" << endl;

    char nome_cliente_geral_para_deletar[5] = "Alex";
    removeClient(waiting_queue, nome_cliente_geral_para_deletar);

    // Deletando um Preferencial
    char nome_cliente_preferencial_para_deletar[12] = "Seu Genesio";
    removeClient(waiting_queue, nome_cliente_preferencial_para_deletar);

    cout << "===============" << endl;

    // Pegando a ordem da fila
    cout << "Pegando nova ordem da lista" << endl;

    int numberClients = waiting_queue->size;
    Client* new_client_order = getQueueOrder(waiting_queue, &numberClients);

    for (int i = 0; i < numberClients; i++) {
        cout << (new_client_order + i)->name << ", ";
    }
    cout << endl;

    delete[] new_client_order;

    // Vendo o próximo cliente
    Client next_client;

    // Atendendo as pessoas
    Client dequeued_client;

    // Mostrando tanto o pŕoximo paciente quando o cara atendido
    int size = waiting_queue->size;

    for (int i = 0; i < size; i++) {
        dequeue(waiting_queue, &dequeued_client);

        cout << "=========================" << endl;
        cout << "Paciente atendido: " << dequeued_client.name << endl;
        cout << "Tamanho atual da fila: " << waiting_queue->size << endl;

        peek(waiting_queue, &next_client);

        cout << "Próximo paciente da fila: " << next_client.name << endl;
    }

    // Adicionando as pessoas novamente para mostrar a função de deletar completamente
    cout << "========================" << endl;
    cout << "Adicionei as pessoas novamente" << endl;

    enqueue(waiting_queue, cliente_1);
    enqueue(waiting_queue, cliente_2);
    enqueue(waiting_queue, cliente_3);
    enqueue(waiting_queue, cliente_4);
    enqueue(waiting_queue, cliente_5);
    enqueue(waiting_queue, cliente_6);
    enqueue(waiting_queue, cliente_7);
    enqueue(waiting_queue, cliente_8);

    cout << "========================" << endl;
    cout << "Removendo as pessoas" << endl;
    cout << "Sem executar a função de remoção, haverá Memmory Leaks" << endl;

    deleteQueue(waiting_queue);
    
    return 0;
}
