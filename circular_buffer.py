
class CircularBuffer:
	def __init__(s,size):
		s._size = size
		s._beg  = 0
		s._data= [0] * size

	def add(s,elem):
		s._beg += 1 
		if s._beg >= s._size :
			s._data[0] = elem
			s._beg = 0
		else:
			s._data[ s._beg ] = elem

	# def __iter__(s):
	# 	class _:
	# 		"""docstring for _"""
	# 		def __init__(self, beg, end):
	# 			self.arg = arg
			
		
	def _getpos(s,i):
		if  -s._size >= i or i >= s._size : raise(IndexError(" list index out of range") )
		pos = i + s._beg
		if pos >= s._size:
			pos -= s._size
		return pos

	def __getitem__(s,i):
		if type(i) == slice:
			raise(IndexError("Slice not supported, future"))
		else:
			return s._data[ s._getpos(i) ]

	def __setitem__(s,i,val):
		s._data[ s._getpos(i) ] = val


	def __repr__(s):
		return s._data.__repr__()



if __name__ == "__main__":
	buffer = CircularBuffer(10)
	print("Buffer: 10")
	_ = [	buffer.add(i) for i in range(112) ]
	print(buffer)
	print('beg = ', buffer._beg)
	print('buffer[0]',buffer[0])
	print('buffer[-1]', buffer[-1])
	print('buffer[-9]', buffer[-9])
	print('buffer[9]', buffer[9])
	# print('buffer[19]',buffer[19])
	# print('buffer[-20]',buffer[-20])
	buffer[:3] = 30
	print(buffer)
	for i in buffer:
		print(i)