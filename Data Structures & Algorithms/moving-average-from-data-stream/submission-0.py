class MovingAverage:
    size = 0;
    array = []
    def __init__(self, size: int):
        self.size = size
        self.array = []

    def next(self, val: int) -> float:
        
        if len(self.array) >= self.size:
            self.array.pop(0)
        self.array.append(val)
        return sum(self.array)/len(self.array)


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)

