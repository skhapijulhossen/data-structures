import array

# Stack


class Stack:
    """
    This Class will implement the Stack data Structure With a Given Size: 
    Operations: push(), pop(), peek(), isEmpty(), free(), add(), sub(), mul(), div(), mod(), power()
    """

    def __init__(self, size: int = 100) -> None:
        self.size = size
        self.top = -1
        self.array = array.array('i', [0 for i in range(size)])

    def push(self, data: int) -> bool:
        """data: integer element to be inserted to top of Stack, returns True if Insertion is successful"""
        if self.top < self.size:
            self.top += 1
            self.array[self.top] = data
            return True
        print("\nStack Overflow!")
        return False

    def pop(self) -> int:
        """removes and returns : data from top of the Stack else -999 if stack is empty"""
        if self.top == -1:
            print("\nStack Underflow!")
            return -999
        data = self.array[self.top]
        del self.array[self.top]
        self.top -= 1
        return data

    def peek(self) -> int:
        """returns: data from top of the Stack"""
        if self.top == -1:
            print("\nStack Underflow!")
            return -999
        return self.array[self.top]

    def isEmpty(self) -> bool:
        """return True if Stack is Empty or False"""
        if self.top == -1:
            return True
        return False

    def free(self) -> int:
        """return free available Space"""
        return self.size - self.top

    def show(self) -> None:
        """Prints all elements"""
        print("Elements:", end=' ')
        for top in range(self.top+1):
            print(self.array[top], end=' =>')


if __name__ == '__main__':
    stack = Stack(10)
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
