#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex mtx; // Mutex para la sincronización

// Estructura para almacenar los parámetros de cada hilo
struct ThreadData {
    const std::vector<int>& array;
    int& result;
};

// Función que suma los elementos de un array y guarda el resultado en result
void sumArray(const ThreadData& data) {
    for (int num : data.array) {
        data.result += num;
    }

    // Bloquear el mutex al finalizar el cálculo
    std::lock_guard<std::mutex> lock(mtx);
}

int main() {
    // Arrays de ejemplo
    std::vector<int> array1 = {1, 2, 3, 4, 5};
    std::vector<int> array2 = {6, 7, 8, 9, 10};

    // Variables para almacenar los resultados de los threads
    int result1 = 0;
    int result2 = 0;
    int finalResult = 0;

    // Crear objetos de estructura para los parámetros de los threads
    ThreadData data1 = {array1, result1};
    ThreadData data2 = {array2, result2};

    // Crear los threads
    std::thread thread1(sumArray, std::ref(data1));
    std::thread thread2(sumArray, std::ref(data2));

    // Esperar a que ambos threads terminen
    thread1.join();
    thread2.join();

    // Bloquear el mutex antes de acceder a los resultados
    std::lock_guard<std::mutex> lock(mtx);

    // Sumar los resultados de los threads en un tercer thread
    finalResult = result1 + result2;

    // Mostrar el resultado final
    std::cout << "Resultado final: " << finalResult << std::endl;

    return 0;
}
