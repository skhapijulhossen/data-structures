#include <iostream>

// Stack Class
class Stack
{
private:
    int size, top;
    int *array;

public:
    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        this->array = new int[size];
        std::cout << "Stack Initialized";
    }

    bool push(int data)
    {
        if (this->top < this->size - 1)
        {
            this->array[++this->top] = data;
            return true;
        }
        std::cout << "Stack Overflow Error!" << std::endl;
        return false;
    }
    int pop()
    {
        int data;
        if (this->top == -1)
        {
            std::cout << "\nStack Underflow";
            return -999;
        }
        data = this->array[top];
        this->array[top] = -1;
        this->top--;
        return data;
    }
    int peek()
    {
        int data;
        if (this->top == -1)
        {
            std::cout << "\nStack Underflow";
            return -999;
        }
        data = this->array[top];
        return data;
    }

    void show()
    {
        for (int i = 0; i <= this->top; i++)
        {
            std::cout << " ->" << this->array[i];
        }
        std::cout << std::endl;
    }

    bool isEmpty()
    {
        if (this->top == -1)
        {
            return true;
        }
        return false;
    }

    int free()
    {
        return this->size - this->top - 1;
    }
};

// main
int main(int argc, char *argv[])
{
    int option, data;
    Stack stack = Stack(5);
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
            stack.push(data);
            break;
        case 2:
            data = stack.pop();
            std::cout << "\n Popped: " << data;
            break;
        case 3:
            stack.show();
            break;
        case 4:
            std::cout << "\nData: " << stack.peek();
            break;
        case 5:
            std::cout << "\nEmpty: " << stack.isEmpty();
            break;
        case 6:
            std::cout << "\nAvailable Space: " << stack.free();
            break;
        default:
            std::cout << "\nChoose Valid Option";
            break;
        }

    } while (option != 0);
    return 0;
}
