/** IMPLEMENTATION OF THE VECTOR **/

int determine_capacity(int initial_capacity);

void doublesize_vector(Vector *vector);


Vector *v_init(unsigned int initial_capacity) {
    
    Vector *vector = malloc(sizeof(vector));

    int capacity = determine_capacity(initial_capacity);

    vector->size = 0;
    vector->capacity = capacity;
    vector->data = malloc(sizeof(int) * capacity);

}

Vector *v_empty_init() {
	return v_init(0);
}

void v_destroy(Vector *vector) {
    free(vector->data);
    free(vector);
}

size_t v_size(Vector *vector) {
	return vector->size;
}

size_t v_capacity(Vector *vector) {
	return vector->capacity;
}	

bool v_is_empty(Vector *vector) {
	return v_size(vector) == 0;
}

int v_at(Vector *vector, unsigned int position) {
	if (position >= v_size(vector)) {
		fprintf(stderr, "v_at: Position %u out of bounds. The size of the vector is %zu.\n\n", position, v_size(vector));
		exit(EXIT_FAILURE);
	}

	return *(vector->data + position * sizeof(int));
}

void v_push(Vector *vector, int value) {
	if (v_capacity(vector) <= v_size(vector)) {
		doublesize_vector(vector);
	}

	*(vector->data + vector->size * sizeof(int)) = value;
	vector->size++;
}



/*****************************/

int determine_capacity(int initial_capacity) {
    int capacity = INITIAL_CAPACITY;
    while (initial_capacity / capacity > 0) {
        capacity <<= 1;
    }
    return capacity;
}

void doublesize_vector(Vector* vector) {
	size_t doubled_capacity = vector->capacity << 1;
	int *doubled_data = malloc(doubled_capacity * sizeof(int));
	memcpy(doubled_data, vector->data, v_capacity(vector));

	free(vector->data);
	vector->data = doubled_data;
	vector->capacity = doubled_capacity;
}

void halfsize_vector() {
	
}
