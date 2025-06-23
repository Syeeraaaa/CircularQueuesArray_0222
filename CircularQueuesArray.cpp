/**
 * @mainpage Documentation circular Queues
 * 
 * @section Introduction
 * project ini merupakan project struktur data 
 * menggunakan struktur data queues dengan pendekatan circular arrays.
 * 
 * @section Operations
 * - en queue for insert element into queues
 * - de queue for delete elements from queues
 * - show data / display
 * 
 * @section How to use
 * 1. Insert
 * 2. Delete
 * 3. Display
 * 4. Exit
 * 
 * @author yProfile
 * - Nama  : Syeera Silvia Erby
 * - NIM   : 20240140222
 * - Kelas : E
 * 
 * @brief 
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright Gibran@umy.ac.id (c) 2025
 * 
 */
#include <iostream>
using namespace std;
 
/**
 * @class Queue 
 * @brief This class is for operation queues
 * 
 */
class Queues
{
private:
    static const int max = 5;
    int FRONT; /// private variable front untuk menunjuk ke elemen pertama
    int REAR; /// private variable reare untuk menunjuk ke elemen terakhir
    int max = 5; /// private max untuk kapasitas dari element 
    int queue_array [5]; /// private variable queue_array digunakan untuk menyimpan elemen

public:
/**
 * @brief Construct a new Queues object
 * set default queues null
 * whit front = -1 and rear = -1
 */
    Queues() 
    {
        FRONT = -1;
        REAR = -1;
    }

    /**
     * @brief method untuk memasukkan data ke queue
     * 
     */
    void insert()
    {
        int num; /// variable num untuk menyimpan input angka yang di masukkan kedalam queue
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        // cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
        {
            cout << "\nQueue overlow\n";
            return;
        }

        // cek apakah antrian kosong
        if (FRONT == -1)
        {
            FRONT = 0;
            REAR = 0;
        }
        else
        {
            // jika REAR berada di posisi terakhir array, kembali ke awal array
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }
    /**
     * @brief method untuk memastikan antrian tidak kosong sebelum menghapus
     * 
     */
    void remove()
    {
        // cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\n The element deleted from the queue is: " << queue_array[FRONT] << "\n";

        // cek jika antrian hanya memiliki satu elemen
        if (FRONT == max - 1)
            FRONT = 0;
        else
        {
            FRONT = FRONT + 1;
        }
    }
    /**
     * @brief method untuk menampilkan semua elemen 
     * 
     */
    void Display()
    {
        int FRONT_position = FRONT; /// variable FRONT_position memiliki fungsi sebagai penunjuk posisi bantu, agar tidak mengganggu variable utama.
        int REAR_position = REAR; /// variable REAR_position memiliki fungsi sebagai penunjuk posisi bantu, agar tidak mengganggu variable utama.

        // cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "\nElements in the queue are...\n";

        // jika FRONT_Position <= REAR_position, iterasi dari front hingga rear
        if (FRONT_position <= REAR_position)
        {
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            cout << endl;
        }
        else
        {
            // jika FRONT_position > REAR_position iterasi front hingga akhir array
            while (FRONT_position <= max - 1)
            {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }

            FRONT_position = 0;

            // iterasi dari awal array hingga REAR
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
    }
};

/**
 * @brief method int main untuk memanggil semua fungsi agar bisa di jalankan
 *
 * 
 * @return int 
 */
int main()
{
    Queues q; /// mendeklarasikkan objek q dari queues
    char ch; /// mendeklarasikkan objek ch dari char

    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case '1':
            {
                q.insert();
                break;
            }
            case '2':
            {
                q.remove();
                break;
            }
            case '3':
            {
                q.Display();
                break;
            }
            case '4':
            {
                return 0;
            }
            default:
            {
                cout<< "Invalid option!!" << endl;
                break;
            }
            }
        }
        catch(exception &e)
        {
            cout << "Check for the values entered." << endl;
        }
    }
}
// fungsi rear untuk menambah data
// fungsi front nilai utama atau index pertama
// ketika rear sudah berada pada ujung idex di sebut circular 
// front + 1 untuk menghapus