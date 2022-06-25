#include <iostream>

// Class
class Queue
{
private:
    int front, rear, size, free;
    int *queue;

public:
    Queue(int size)
    {
        this->front = 0;
        this->rear = -1;
        this->size = size - 1;
        this->free = size - 1;
        this->queue = new int[size - 1];
        std::cout << "\nQueue Initialized!";
    }

    int enqueue(int data)
    {
        if (this->free == 0)
        {
            std::cout << "\n Queue id Full";
            return 0;
        }

        this->rear++;
        this->rear = this->rear % this->size;
        this->queue[this->rear] = data;
        this->free--;
        return 1;
    }

    int dequeue()
    {
        if (this->free == this->size)
        {
            std::cout << "\nQueue is Empty!";
            return -1;
        }
        int data = this->queue[this->front];
        this->front++;
        this->front = this->front % this->size;
        this->free++;
        return data;
    }

    void show()
    {
        int tempFront, count = 0;
        tempFront = this->front;
        while (count < (this->size - this->free))
        {
            std::cout << "=>" << this->queue[tempFront];
            ++tempFront;
            tempFront = tempFront % this->size;
            count++;
        }
    }

    int peek()
    {
        return this->queue[this->front];
    }

    bool isEmpty()
    {
        if (this->size == this->free)
        {
            return 1;
        }
        return 0;
    }

    int freeSpace()
    {
        return this->free;
    }
};

int main(int argc, char *argv[])
{
    int option, data;
    Queue queue = Queue(5);
    do
    {
        std::cout << "\n=======Choose======" << std::endl;
        std::cout << "1.Push || 2.Pop || 3.show || 4.Peek || 5. isEmpy || 6.free : ";
        std::cin >> option;
        switch (option)
        {
        case 1:
            std::cout << "\n Enter Data:";
            std::cin >> data;
            queue.enqueue(data);
            break;
        case 2:
            data = queue.dequeue();
            std::cout << "\n Popped: " << data;
            break;
        case 3:
            queue.show();
            break;
        case 4:
            std::cout << "\nData: " << queue.peek();
            break;
        case 5:
            std::cout << "\nEmpty: " << queue.isEmpty();
            break;
        case 6:
            std::cout << "\nAvailable Space: " << queue.freeSpace();
            break;
        default:
            std::cout << "\nChoose Valid Option";
            break;
        }

    } while (option != 0);
    return 0;
}
