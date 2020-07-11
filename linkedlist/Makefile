#!/usr/bin/make -f

include ../MakeVars

$(BUILD_DIR)/linkedlist.t: $(BUILD_DIR)/linkedlist.t.o $(BUILD_DIR)/linkedlist.o
	$(CC) $(CFLAGS) $^ -o $@
	echo $(SOURCE_DIR)/%.t.c $(INCLUDE_DIR)/%.h

$(BUILD_DIR)/%.t.o: $(SOURCE_DIR)/%.t.c $(INCLUDE_DIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@
	
$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c $(INCLUDE_DIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@


#linkedlist.t.o: source/linkedlist.t.c include/linkedlist.h
#	$(CC) $(CFLAGS) -c source/linkedlist.t.c

#linkedlist.o: source/linkedlist.c include/linkedlist.h
#	$(CC) $(CFLAGS) -c source/linkedlist.c

.PHONY: clean
clean: ; rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/linkedlist.t
