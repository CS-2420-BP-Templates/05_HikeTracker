# Hike Tracker
## Description

In this lab, you will create a generic Collection class using C++ templates. Your collection will store elements of any data type in a fixed-size array and provide methods for adding, removing, and accessing items.

You will also use exception handling to detect and respond to invalid operations, such as accessing an invalid index or adding an item to a full collection.

## Requirements
Create a class template named:

```Collection<T, MAX_SIZE>```

- T represents the data type stored in the Collection
- MAX_SIZE represents the maximum number of elements the collection can store.

## Member Variables
Your class should contain:
```angular2html
T items[MAX_SIZE];
int size;
```
The size variable should track the number of elements currently stored in the collection.

## Required Methods
### Constructor

Initialize the collection as empty.

```Collection();```

### add()
Adds an item to the end of the Collection.

```void add(const T& item);```
- Add the item to the next available position.
- Increase the size.
- Throw an overflow_error if the collection is already full.

### removeAt()
Removes at the specific index.
```void removeAt(int index);```

- Shift all remaining elements to fill the gap.
- Decrease the size.
- Throw an out_of_range exception if the index is invalid.
- Throw an underflow_error if the collection is empty.

### operator[] 
Gives access to the item at position index

```T& operator[](int index);```

- Returns the requested item at the specified index.
- Throw an out_of_range exception if the index is invalid.

### getSize()
Returns the current number of items stored

```int getSize() const;```


### operator <<

Displays all items in the collection.
```friend ostream& operator<<(ostream&, const Collection&)```

Example Output:
```angular2html
Apple
Orange
Banana
```

## Main method
Allow the user to keep track of hiking destinations and distances.


Your program will use two instances of your Collection<T, MAX_SIZE> class:
```angular2html
Collection<string, 20> trailNames;
Collection<int, 20> trailDistances;
```


The first collection stores the trail name, while the second collection stores the trail distance in miles.

Each trail name and distance should be stored at the same index in their respective collections.


## Sample Output

```angular2html
Hiking Destination Tracker --------------------------
1. Add Trail
2. Remove Trail
3. View All Trails
4. Exit

Enter choice: 1

Enter trail name: Beus Canyon
Enter trail distance (miles): 3
Trail added successfully.


1. Add Trail 
2. Remove Trail
3. View All Trails 
4. Exit 

Enter choice: 1 

Enter trail name: Mount Timpanogos 
Enter trail distance (miles): 14 
Trail added successfully.

1. Add Trail
2. Remove Trail
3. View All Trails
4. Exit

Enter choice: 2
1. Beus Canyon
2. Mount Timpanogos

Which position to remove?
Enter Choice: 1
Trail removed

1. Add Trail
2. Remove Trail
3. View All Trails
4. Exit


```