class Deep {
public:
    int* data;

    Deep(int d) {
        data = new int(d); // Allocate memory
    }

    // Deep copy constructor
    Deep(const Deep& source) {
        data = new int(*source.data); // Allocate memory for the copy and copy the value
    }

    ~Deep() {
        delete data; // Free memory
    }
};

int main() {
    Deep obj1(100);
    Deep obj2 = obj1; // Deep copy

    // obj1 and obj2 have independent memory locations
}


/*
Deep Copy:
Copies both pointers and the memory they point to.
Requires explicit implementation (custom copy constructors and assignment operators).
Avoids issues with shared memory, providing independent copies.

A deep copy duplicates not only the values of the data members but also the
memory those pointers refer to. Each object will have its own independent
copy of the dynamically allocated data.

In this example, obj1 and obj2 have their own independent copies of the data.
Changes made to one object's data do not affect the other.


*/