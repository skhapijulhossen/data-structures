import numpy as np

# Class Queue


class Queue:
    """
    size = 100
    dtypes = int, float, string, complex
    """

    def __init__(self, size: int = 100, dtype: str = 'int') -> None:
        self.size = size - 1
        self.dtypes = {'int': int, 'float': float,
                       'string': str, 'complex': complex}
        self.dtype = self.dtypes.get(dtype) if self.dtypes.get(
            dtype) else self.dtypes.get('int')
        self.queue = np.zeros((size,), dtype=self.dtype)
        self.front = -1
        self.rear = -1
        self.free = size - 1

    def enqueue(self, data: int) -> bool:
        if self.free == 0:
            print("Queue Full!")
            return False
        if type(data) != self.dtype:
            print("TypeError!")
            return False
        self.queue[self.rear] = data
        self.free -= 1
        self.rear += 1
        self.rear %= self.size
        return True

    def dequeue(self):
        if self.free == self.size:
            print("Queue is Empty!")
            return None
        data = self.queue[self.front]
        self.front += 1
        self.front %= self.size
        self.free += 1
        return data

    def show(self):
        if self.free == self.size:
            print("Queue is Empty!")
            return
        tempFront, tempRear = self.front, self.rear
        count = 0
        while count < (self.size - self.free):
            print(self.queue[tempFront], end='=>')
            tempFront += 1
            tempFront %= self.size
            count += 1

    def freeSpace(self) -> int:
        return self.free

    def peek(self) -> int:
        return self.queue[self.front]


if __name__ == '__main__':
    queue = Queue(5)
    while True:
        option = input(
            "\nChoose: 1.Enqueue() 2.Dequeue() 3.Peek() 4.isEmpty() 5.free() 6.Show() -1. Exit: ")
        if option == '1':
            data = int(input("Data: "))
            queue.enqueue(data)
        elif option == '2':
            print(f'Poped Data: {queue.dequeue()}')
        elif option == '3':
            print(f'Peek Data: {queue.peek()}')
        elif option == '4':
            print(f'Is Empty: {queue.isEmpty()}')
        elif option == '5':
            print(f'AVailable Space: {queue.freeSpace()}')
        elif option == '6':
            queue.show()
        if option == '-1':
            exit()
        else:
            print("Choose Valid Option")
