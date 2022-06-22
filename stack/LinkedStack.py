# Implemntation of Stack using LinkedList

# Node Class to store data and Linked Node
from numpy import true_divide


class Node:
    def __init__(self, data: int) -> None:
        self.data = data
        self.prev = None

# LinkedStack class to maintain Stack


class LinkedStack:
    def __init__(self, size: int) -> None:
        self.size = size
        self.top = None
        self.count = 0

    def push(self, data: int) -> bool:
        if self.count == self.size:
            print("Stack Overflow!")
            return False
        if self.top == None:
            self.top = Node(data)
            self.prev = None
            self.count += 1
            return True
        temp = self.top
        self.top = Node(data)
        self.top.prev = temp
        self.count += 1
        return True

    def pop(self) -> int:
        if self.top == None:
            print("Stack Underflow!")
            return -999
        data = self.top.data
        self.top = self.top.prev
        self.count -= 1
        return data

    def show(self):
        if not self.top:
            print('Stack Empty!')
            return
        temp = self.top
        while temp.prev:
            print(temp.data, end='=>')
            temp = temp.prev
        print(temp.data)

    def peek(self) -> int:
        if self.top:
            return self.top.data
        return -999

    def isEmpty(self) -> bool:
        if self.top:
            return False
        return True

    def free(self):
        return self.size - self.count


if __name__ == '__main__':
    stack = LinkedStack(5)

    while True:
        option = input(
            "\nChoose: 1.Push() 2.Pop() 3.Peek() 4.isEmpty() 5.free() 6.Show() -1. Exit: ")
        if option == '1':
            data = int(input("Data: "))
            stack.push(data)
        elif option == '2':
            print(f'Poped Data: {stack.pop()}')
        elif option == '3':
            print(f'Peek Data: {stack.peek()}')
        elif option == '4':
            print(f'Is Empty: {stack.isEmpty()}')
        elif option == '5':
            print(f'AVailable Space: {stack.free()}')
        elif option == '6':
            stack.show()
        else:
            print("Choose Valid Option")
