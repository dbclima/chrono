typedef enum
{
	HAS_ARGUMENTS,
	NO_ARGUMENTS
}
opt_arg_rule_t;

#define OPT_TYPES		\
	X(STR, char*)		\
	X(FLAG, int)		\
	X(INT, int)		\
	X(FLOAT, float)		\

typedef enum
{
	#define X(name, type) OPT_TYPE_ ## name,
	OPT_TYPES
	#undef X
}
opt_type_t;

typedef union
{
	#define X(name, type) type name ## _val;
	OPT_TYPES
	#undef X
}
opt_value_t;

typedef struct
{
	char short_name;
	char* full_name;
	opt_type_t type;
	char* hint;
	opt_arg_rule_t has_arg;
	opt_value_t dft_value;
}
opt_t;
