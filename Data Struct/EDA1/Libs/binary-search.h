int binary_search (int* array, int size, int key) {
    int l = 0, r = size - 1;

    while (l <= r)
    {
        int middle = l + (r - l) / 2;

        if (array[middle] == key) return middle;
        else if (array[middle] < key) l = middle + 1;
        else r = middle - 1;
    }
    
    return -1;
}
