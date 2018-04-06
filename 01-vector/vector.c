
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
	double_capacitize_vector_if_needed(vector);

	*(vector->data + v_size(vector) * sizeof(int)) = value;
	vector->size++;
}

int v_pop(Vector *vector) {
	int popped = v_at(vector, v_size(vector) - 1);
	vector->size--;

	half_capacitize_vector_if_needed(vector);
	return popped;
}

/*****************************/

int determine_capacity(int initial_capacity) {
    int capacity = INITIAL_CAPACITY;
    while (initial_capacity / capacity > 0) {
        capacity <<= 1;
    }
    return capacity;
}

void double_capacitize_vector_if_needed(Vector* vector) {
	if (v_capacity(vector) > v_size(vector)) {
		return;
	}
	size_t doubled_capacity = vector->capacity << 1;
	re_capacitize_vector(vector, doubled_capacity);
}

void half_capacitize_vector_if_needed(Vector *vector) {
	if (vector->size > vector->capacity * REDUCTION_FACTOR) {
		return;		
	}
    size_t half_capacity = vector->capacity >> 1;
    re_capacitize_vector(vector, half_capacity);
}

void re_capacitize_vector(Vector *vector, size_t new_capacity) {
	int *resized_data = malloc(new_capacity * sizeof(int));
	memcpy(resized_data, vector->data, v_capacity(vector));
    free(vector->data);
    vector->data = resized_data;
	vector->capacity = new_capacity;
}

void halfsize_vector() {
	
}
