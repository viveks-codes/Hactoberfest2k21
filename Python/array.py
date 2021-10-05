class Array():
	__array = None
	def __init__(self):
		self.__array = []
	
	@property
	def size(self):
		return len(self.__array)

	@property
	def is_empty(self):
		return True if self.size == 0 else False

	def at(self, index: int) -> object:
		if not index > self.size and not self.is_empty:
			return self.__array[index]
		return None

	def push(self, item: object):
		self.__array.append(item)
	
	def insert(self, item: object, index: int):
		new = []
		for i in range(0, index):
			new.append(self.__array[i])
		new.append(item)
		for i in range(index, self.size):
			new.append(self.__array[i])
		self.__array.clear()
		self.__array.extend(new)
	
	def prepend(self, item: object):
		self.insert(item, 0)

	def pop(self):
		return self.__array.pop()

	def delete(self, index: int):
		new = []
		for i in range(0, index):
			new.append(self.__array[i])
		for i in range(index+1, self.size):
			new.append(self.__array[i])
		self.__array.clear()
		self.__array.extend(new)

	def remove(self, item: object):
		new = []
		for i in self.__array:
			if not i == item:
				new.append(i)
		self.__array.clear()
		self.__array.extend(new)

	def find(self, item: object) -> int:
		return self.__array.index(item)	

	def printArray(self):
		print(self.__array)
