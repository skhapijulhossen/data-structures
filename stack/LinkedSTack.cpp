#include <iostream>

class Node
{
public:
    int data;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
    }
};

// Stack Class
class Stack
{
private:
    int size, count;
    Node *top;

public:
    Stack(int size)
    {
        this->size = size;
        this->count = 0;
        std::cout << "Stack Initialized";
    }

    bool push(int data)
    {
        if (this->count < this->size)
        {
            Node *node = new Node(data);
            if (this->count == 0)
            {

                this->top = node;
                this->top->prev = NULL;
                this->count++;
                return true;
            }
            Node *temp = this->top;
            this->top = node;
            this->top->prev = temp;
            this->count++;
            return true;
        }
        std::cout << "Stack Overflow Error!" << std::endl;
        return false;
    }

    int pop()
    {
        int data;
        if (this->count == 0)
        {
            std::cout << "\nStack Underflow";
            return -999;
        }
        data = this->top->data;
        this->top = this->top->prev;
        this->count--;
        return data;
    }
    int peek()
    {
        if (this->count == 0)
        {
            std::cout << "\nStack Underflow";
            return -999;
        }
        return this->top->data;
    }

    void show()
    {
        if (this->count == 0)
        {
            return;
        }
        Node *temp = this->top;
        while (temp->prev)
        {
            std::cout << " ->" << temp->data;
            temp = temp->prev;
        }
        std::cout << "->" << temp->data << std::endl;
    }

    bool isEmpty()
    {
        if (this->count == 0)
        {
            return true;
        }
        return false;
    }

    int free()
    {
        return this->size - this->count;
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
