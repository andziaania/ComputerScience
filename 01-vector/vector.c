
Vector *v_init(size_t requested_capacity) {
    
    Vector *vector = malloc(sizeof(Vector));

    size_t capacity = get_the_round_up_to_the_next_power_of_two(requested_capacity);

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

int v_at(Vector *vector, size_t position) {
	if (position >= v_size(vector)) {
		fprintf(stderr, "v_at: Position %zu out of bounds. The size of the vector is %zu.\n\n", position, v_size(vector));
		exit(EXIT_FAILURE);
	}

	return *(vector->data + position);
}

void v_push(Vector *vector, int value) {
	double_capacitize_vector_if_needed(vector);

	size_t last_position = v_size(vector);
	setAt(vector, last_position, value);
	vector->size++;
}

int v_pop(Vector *vector) {
	int popped = v_at(vector, v_size(vector) - 1);
	vector->size--;

	half_capacitize_vector_if_needed(vector);
	return popped;
}

void v_insert(Vector *vector, size_t index, int value) {
    int initial_size = vector->size;
    vector->size++;
    double_capacitize_vector_if_needed(vector);

    memmove(vector->data + index + 1, vector->data + index, (initial_size - index) * sizeof(int));
    setAt(vector, index, value);
}

void v_prepend(Vector *vector, int value) {
    v_insert(vector, 0, value);
}

void v_delete(Vector *vector, size_t index) {
    if (v_size(vector) == 0 || index >= v_size(vector)) {
        return;
    }

    memmove(vector->data + index, vector->data + index + 1, (v_size(vector) - index - 1) * sizeof(int));
    vector->size--;
    half_capacitize_vector_if_needed(vector);
}

int v_find(Vector *vector, int item) {
    for (size_t i = 0; i < v_size(vector); i++) {
        if (v_at(vector, i) == item) {
            return i;
        }
    }
    return -1;
}

void v_remove(Vector *vector, int item) {
    if (v_size(vector) == 0) {
        return;
    }

    size_t searchedItemIndex = 0;
    size_t insertionItemIndex = 0;

    for (; searchedItemIndex < v_size(vector); searchedItemIndex++, insertionItemIndex++) {
        while (searchedItemIndex < v_size(vector) && v_at(vector, searchedItemIndex) == item) {
            searchedItemIndex++;
        }

        if (searchedItemIndex == v_size(vector)) {
            // We finished scanning. We will not include the item under searchedItemIndex.
            break;
        }
        setAt(vector, insertionItemIndex, v_at(vector, searchedItemIndex));
    }
    vector->size = insertionItemIndex;
    half_capacitize_vector_if_needed(vector);
}


/*****************************/

size_t get_the_round_up_to_the_next_power_of_two(size_t value) {
	if (value <= INITIAL_CAPACITY) {
		return INITIAL_CAPACITY;
	}
	value--;
	value |= value >> 1;  // handle  2 bit numbers
	value |= value >> 2;  // handle  4 bit numbers
	value |= value >> 4;  // handle  8 bit numbers
	value |= value >> 8;  // handle 16 bit numbers
	if (sizeof(value) > 2) {
		value |= value >> 16; // handle 32 bit numbers
	}
	value++;
	return value;	
}

void double_capacitize_vector_if_needed(Vector* vector) {
	if (v_capacity(vector) > v_size(vector)) {
		return;
	}
	size_t doubled_capacity = vector->capacity << 1;
	re_capacitize_vector(vector, doubled_capacity);
}

/**
 * When popping an item, if size is 1/4 of capacity, resize to half
 */
void half_capacitize_vector_if_needed(Vector *vector) {
	if (v_capacity(vector) == INITIAL_CAPACITY ||
			vector->size > vector->capacity * REDUCTION_FACTOR) {
		return;		
	}
	size_t half_capacity = vector->capacity >> 1;
    re_capacitize_vector(vector, half_capacity);
}

void re_capacitize_vector(Vector *vector, size_t new_capacity) {
	int *resized_data = malloc(new_capacity * sizeof(int));
	memcpy(resized_data, vector->data, v_size(vector) * sizeof(int));
    free(vector->data);
    vector->data = resized_data;
	vector->capacity = new_capacity;
}

void setAt(Vector *vector, size_t index, int value) {
    *(vector->data + index) = value;
}

