#include <CppUTest/TestHarness.h>

extern "C"
{
	#include "../src/ep1.h"
}

TEST_GROUP(conversao)
{
	char *string;

	void setup()
	{
	}

	void teardown()
	{
		free(string);
	}
};

/*
	Testes conversão binária
*/

TEST(conversao, zero_para_binario)
{
	string = converte(0, 2);
	STRCMP_EQUAL("0.0", string);
}

TEST(conversao, numero_inteiro_para_binario)
{
	string = converte(8, 2);
	STRCMP_EQUAL("1000.0", string);
}

TEST(conversao, numero_fracionario_zero_para_binario)
{
	string = converte(8.0, 2);
	STRCMP_EQUAL("1000.0", string);
}

TEST(conversao, numero_com_parte_fracionaria_para_binario)
{
	string = converte(785.125, 2);
	STRCMP_EQUAL("1100010001.001", string);
}

TEST(conversao, numero_fracionario_para_binario)
{
	string = converte(0.125, 2);
	STRCMP_EQUAL("0.001", string);
}

TEST(conversao, dizima_periodica_para_binario)
{
	string = converte(0.1, 2);
	STRCMP_EQUAL("0.00011001100110011001", string);
}

/*
	Testes conversão Octal
*/

TEST(conversao, zero_para_octal)
{
	string = converte(0, 8);
	STRCMP_EQUAL("0.0", string);
}

TEST(conversao, numero_inteiro_para_octal)
{
	string = converte(10, 8);
	STRCMP_EQUAL("12.0", string);
}

TEST(conversao, numero_fracionario_zero_para_octal)
{
	string = converte(219.0, 8);
	STRCMP_EQUAL("333.0", string);
}

TEST(conversao, numero_com_parte_fracionaria_para_octal)
{
	string = converte(219.59375, 8);
	STRCMP_EQUAL("333.46", string);
}

TEST(conversao, numero_fracionario_para_octal)
{
	string = converte(0.359375, 8);
	STRCMP_EQUAL("0.27", string);
}

/*
	Testes conversão Hexadecimal
*/

TEST(conversao, zero_para_hexadecimal)
{
	string = converte(0, 16);
	STRCMP_EQUAL("0.0", string);
}

TEST(conversao, numero_inteiro_para_hexadecimal)
{
	string = converte(142, 16);
	STRCMP_EQUAL("8E.0", string);
}

TEST(conversao, numero_fracionario_zero_para_hexadecimal)
{
	string = converte(19.0, 16);
	STRCMP_EQUAL("13.0", string);
}

TEST(conversao, numero_com_parte_fracionaria_para_hexadecimal)
{
	string = converte(216.4765625, 16);
	STRCMP_EQUAL("D8.7A", string);
}

TEST(conversao, numero_fracionario_para_hexadecimal)
{
	string = converte(0.4765625, 16);
	STRCMP_EQUAL("0.7A", string);
}

/*
	Testes conversão com valores negativos
*/

TEST(conversao, valor_negativo_binario)
{
	string = converte(-123, 2);
	STRCMP_EQUAL("-1111011.0", string);
}

TEST(conversao, valor_negativo_octal)
{
	string = converte(-123, 8);
	STRCMP_EQUAL("-173.0", string);
}

TEST(conversao, valor_negativo_hexadecimal)
{
	string = converte(-123, 16);
	STRCMP_EQUAL("-7B.0", string);
}