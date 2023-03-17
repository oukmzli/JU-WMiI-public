#include "main.cpp"
#include "gtest.h"

TEST(FormatujNapis, MainTest) {
    EXPECT_EQ(FormatujNapis("ABCD{p:5:x}X Y Z", "abc", "cdef", "xyz"), "ABCDxxxxxX Y Z");
    EXPECT_EQ(FormatujNapis("ABCD{u:3}X Y Z", "abc", "cdef", "xyz"), "ABCD Z");
    EXPECT_EQ(FormatujNapis("ABCD{U:2}X Y Z", "abc", "cdef", "xyz"), "ABX Y Z");
    EXPECT_EQ(FormatujNapis("ABCD{w:2}X Y Z", "abc", "cdef", "xyz"), "ABCDcdefX Y Z");
    EXPECT_EQ(FormatujNapis("ABCD{W:2:3}X Y Z", "abc", "cdef", "xyz"), "ABCDcdeX Y Z");
    EXPECT_EQ(FormatujNapis("ABCD{W:2:5}X Y Z", "abc", "cdef", "xyz"), "ABCDcdef X Y Z");
    EXPECT_EQ(FormatujNapis("A{p:4:a}le {w:1}tra nudny t{w:1}t. {u:3}UsuCam{U:2}{W:2:3}{W:3:3}.", "eks", "zy", "niebyt"),
            "Aaaaale ekstra nudny tekst. Czy nie.");
    EXPECT_EQ(FormatujNapis("ABCD{W:2:5X Y Z", "abc", "cdef", "xyz"), "ABCD{W:2:5X Y Z");
}

TEST(UsunSlowo, MainTest) {
    EXPECT_EQ(UsunSlowo("Smok Wawelski ryczy ku uciesze gawiedzi", 2), "Smok  ryczy ku uciesze gawiedzi");
    EXPECT_EQ(UsunSlowo("Smok Wawelski ryczy ku uciesze gawiedzi", 1), " Wawelski ryczy ku uciesze gawiedzi");
    EXPECT_EQ(UsunSlowo("Smok Wawelski ryczy ku uciesze gawiedzi", 0), "Smok Wawelski ryczy ku uciesze gawiedzi");
    EXPECT_EQ(UsunSlowo("Smok Wawelski ryczy ku uciesze gawiedzi", 6), "Smok Wawelski ryczy ku uciesze ");
    EXPECT_EQ(UsunSlowo("Smok      Wawelski      ryczy ku uciesze gawiedzi", 6), "Smok      Wawelski      ryczy ku uciesze ");
    EXPECT_EQ(UsunSlowo("Smok Wawelski ryczy ku uciesze gawiedzi", 7), "Smok Wawelski ryczy ku uciesze gawiedzi");
    EXPECT_EQ(UsunSlowo("", 7), "");
}

TEST(NajwiekszeSlowo, MainTest) {
    EXPECT_EQ(NajwiekszeSlowo("Smok Wawelski ryczy ku uciesze gawiedzi"), "uciesze");
    EXPECT_EQ(NajwiekszeSlowo("Smok Wawelski uciesze ryczy ku uciesze gawiedzi"), "uciesze");
    EXPECT_EQ(NajwiekszeSlowo("Smok Wawelski uciesze ryczy ku gawiedzi uciesze"), "uciesze");
    EXPECT_EQ(NajwiekszeSlowo("uciesze Smok Wawelski uciesze ryczy ku gawiedzi"), "uciesze");
    EXPECT_EQ(NajwiekszeSlowo(" uciesze Smok Wawelski uciesze ryczy ku gawiedzi"), "uciesze");
    EXPECT_EQ(NajwiekszeSlowo(" uciesze  Smok Wawelski uciesze ryczy ku gawiedzi"), "uciesze");
    EXPECT_EQ(NajwiekszeSlowo("Smok Wawelski uciesze ryczy ku gawiedzi uciesze "), "uciesze");
    EXPECT_EQ(NajwiekszeSlowo("Smok Wawelski uciesze ryczy ku gawiedzi uciesze  "), "uciesze");
    EXPECT_EQ(NajwiekszeSlowo("Smok Wawelski uciesze ryczy ku gawiedzi  uciesze "), "uciesze");
    EXPECT_EQ(NajwiekszeSlowo("Smok Wawelski uciesze ryczy ku gawiedzi zzzzzzzzzz uciesze "), "zzzzzzzzzz");
    EXPECT_EQ(NajwiekszeSlowo("zz zzzzzz zzzzzzzzzz zzz "), "zzzzzzzzzz");
    EXPECT_EQ(NajwiekszeSlowo("    zzzzzzzzzz     "), "zzzzzzzzzz");
    EXPECT_EQ(NajwiekszeSlowo("Smok Wawelski aaaaaaaaaaaa uciesze ryczy ku gawiedzi uciesze "), "uciesze");
    EXPECT_EQ(NajwiekszeSlowo("      "), "");
    EXPECT_EQ(NajwiekszeSlowo("Smok     Wawelski      uciesze     ryczy      ku     gawiedzi   uciesze  "), "uciesze");
    EXPECT_EQ(NajwiekszeSlowo("zzzzzzzzzz"), "zzzzzzzzzz");
}

TEST(NormalizujNapis, MainTest) {
    EXPECT_EQ(NormalizujNapis("Oto   Ala   .Ma kota ,lecz nie ma psa     ."), "Oto Ala. Ma kota, lecz nie ma psa.");
    EXPECT_EQ(NormalizujNapis("     Oto   Ala   .Ma kota ,lecz nie ma psa     ."), "Oto Ala. Ma kota, lecz nie ma psa.");
    EXPECT_EQ(NormalizujNapis("     Oto   Ala   .Ma kota ,lecz nie ma psa     .     "), "Oto Ala. Ma kota, lecz nie ma psa.");
    EXPECT_EQ(NormalizujNapis("Oto   Ala   .Ma kota ,lecz nie ma psa     .     "), "Oto Ala. Ma kota, lecz nie ma psa.");
    EXPECT_EQ(NormalizujNapis("     Oto   Ala   .Ma kota ,lecz nie ma psa     ."), "Oto Ala. Ma kota, lecz nie ma psa.");
    EXPECT_EQ(NormalizujNapis("     Oto   Ala   .Ma kota    ,lecz nie ma psa     ."), "Oto Ala. Ma kota, lecz nie ma psa.");
    EXPECT_EQ(NormalizujNapis("Oto.Ala,Ma.kota,lecz,nie.ma.psa."), "Oto. Ala, Ma. kota, lecz, nie. ma. psa.");
    EXPECT_EQ(NormalizujNapis(""), "");
    EXPECT_EQ(NormalizujNapis("    "), "");
    EXPECT_EQ(NormalizujNapis("."), ".");
    EXPECT_EQ(NormalizujNapis(","), ",");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
