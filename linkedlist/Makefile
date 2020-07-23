#!/usr/bin/make -f

include ../MakeVars

OBJECTS = $(BUILD_DIR)/linkedlist.t.o $(BUILD_DIR)/linkedlist.o

$(BUILD_DIR)/linkedlist.t: $(OBJECTS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.t.o: $(SOURCE_DIR)/%.t.c $(INCLUDE_DIR)/%.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c $(INCLUDE_DIR)/%.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean: ; rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/linkedlist.t

$(BUILD_DIR):
	mkdir $@
