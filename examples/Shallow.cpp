class Shallow
{
public:
	int *data;

	Shallow(int d)
	{
		data = new int(d); // Allocate memory
	}

	// Shallow copy constructor
	Shallow(const Shallow &source) : data(source.data) {}

	~Shallow()
	{
		delete data; // Free memory
	}
};

int main()
{
	Shallow obj1(100);
	Shallow obj2 = obj1; // Shallow copy

	// Both obj1 and obj2 data members point to the same memory location
}


/*
Shallow Copy:
Copies pointers, not the memory they point to.
Fast and default in standard copy constructors and assignment operators.
Can lead to issues like double free errors and dangling pointers.

A shallow copy duplicates the values of the data members of an object.
If the data member is a pointer, the pointer itself is copied but not the
memory it points to. This means that the original and the copy will point
to the same memory location.

In this example, both obj1 and obj2 point to the same memory location.
If one object modifies the data, the change will be visible in the other.
When one object is destroyed, it will delete the memory, leaving the other
pointing to a deallocated area (dangling pointer).
*/