#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "romanos.hpp"

TEST_CASE( "Numeros romanos - algarismos únicos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("I") == 1 );
    REQUIRE( romanos_para_decimal("V") == 5 );
    REQUIRE( romanos_para_decimal("X") == 10 );
    REQUIRE( romanos_para_decimal("L") == 50 );
    REQUIRE( romanos_para_decimal("C") == 100 );
    REQUIRE( romanos_para_decimal("D") == 500 );
    REQUIRE( romanos_para_decimal("M") == 1000 );
}

TEST_CASE( "Numeros romanos - 2 algarismos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("II") == 2 );
    REQUIRE( romanos_para_decimal("XX") == 20);
    REQUIRE( romanos_para_decimal("CC") == 200);
    REQUIRE( romanos_para_decimal("MM") == 2000);
}

TEST_CASE( "Numeros romanos - 2 algarismos diferentes", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("VI") == 6 );
    REQUIRE( romanos_para_decimal("XI") == 11 );
    REQUIRE( romanos_para_decimal("LI") == 51 );
    REQUIRE( romanos_para_decimal("CI") == 101 );
    REQUIRE( romanos_para_decimal("DI") == 501 );
    REQUIRE( romanos_para_decimal("MI") == 1001 );
}

TEST_CASE( "Numeros romanos - algarismo na forma de subtração", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("IV") == 4 );
    REQUIRE( romanos_para_decimal("IX") == 9 );
    REQUIRE( romanos_para_decimal("XL") == 40 );
    REQUIRE( romanos_para_decimal("XC") == 90 );
    REQUIRE( romanos_para_decimal("CD") == 400 );
    REQUIRE( romanos_para_decimal("CM") == 900 );
}

TEST_CASE( "Numeros romanos - números grandes aleatórios", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("CCLVIII") == 258 );
    REQUIRE( romanos_para_decimal("CMXXXVII") == 937 );
    REQUIRE( romanos_para_decimal("CMLXXXIX") == 989 );
}

TEST_CASE( "Numeros romanos inválidos - algarismos repetidos mais que tres vezes", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("IIII") == -1 );
    REQUIRE( romanos_para_decimal("XXXX") == -1 );
}

TEST_CASE( "Numeros romanos inválidos - algarismos como V, L e D repetidos mais que uma vez", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("VV") == -1 );
    REQUIRE( romanos_para_decimal("LL") == -1 );
    REQUIRE( romanos_para_decimal("DD") == -1 );
}

TEST_CASE( "Numeros romanos inválidos - algarismos como V, L e D usados na operação de subtração", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("VX") == -1 );
    REQUIRE( romanos_para_decimal("VC") == -1 );
    REQUIRE( romanos_para_decimal("LC") == -1 );
    REQUIRE( romanos_para_decimal("DM") == -1 );
}

TEST_CASE( "Numeros romanos inválidos - algarismos que podem ser usados para subtração, porém nao mais de uma vez", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("IIX") == -1 );
    REQUIRE( romanos_para_decimal("XXC") == -1);
}

TEST_CASE( "Numeros romanos - ordem inválida de algorismos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("IC") == -1 );
    REQUIRE( romanos_para_decimal("VX") == -1 );
}

TEST_CASE( "Numeros romanos inválidos - 1 algarismo inválido", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("W") == -1 );
    REQUIRE( romanos_para_decimal("i") == -1 );
}

TEST_CASE( "Numeros romanos inválidos - com algarismo inválido", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("IG") == -1 );
    REQUIRE( romanos_para_decimal("Xi") == -1 );
}

TEST_CASE( "Numeros romanos inválidos - algarismos maior que 3000", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("MMMI") == -1 );
    REQUIRE( romanos_para_decimal("MMMX") == -1 );
}


