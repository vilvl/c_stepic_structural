enum either_type { ET_INT, ET_STRING };

struct either_int_string {
  enum either_type type;
  union {
    char* as_string;
    int64_t as_int;
  };
};


// Создание экземпляров из строки или из числа
// Всегда передаётся строка, выделенная в куче
struct either_int_string either_from_string(char* s) {
    return (struct either_int_string) {.type = ET_STRING, .as_string = s}; 
}
struct either_int_string either_from_int(int64_t i) {
    return (struct either_int_string) {.type = ET_INT, .as_int = i}; 
}

// очистить память под строку (если строка)
void either_int_string_destroy(struct either_int_string e) {
    if (e.type != ET_STRING || !e.as_string ) return;
    free( e.as_string );
}

// конструкция switch используется для ветвления по значению числа,
// например, перечисления.
// Для строк и других типов данных использоваться не может
// Каждая ветка должна завершаться break
void print(struct either_int_string e) {
  switch (e.type) {
  case ET_INT: {
       printf("Int %" PRId64, e.as_int);
       break;
  }
  case ET_STRING: {
       printf("String %s", e.as_string);  
       break;
  }
  // Ветка по-умолчанию, если e.type не равен ни ET_INT, ни ET_STRING
  default: {
      break;
  }
  }
}

struct heap_string {
  char* addr;
};

// скопировать в кучу
struct heap_string halloc( const char* s ){
    
    size_t size = 0;
    while ( s[size++] != '\0' );
    
    char* ptr = malloc( sizeof *ptr * size );
    while ( *ptr++ = *s++ );
    for ( size_t i = 0; i < size; i++ ){
        ptr[i] = s[i];
    }
    return (struct heap_string) { .addr = ptr };
}
// освободить память
void heap_string_free( struct heap_string h ){
    free(h.addr);
}

