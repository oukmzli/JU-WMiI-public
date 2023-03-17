#include <iostream>
#include "test.hpp"

int main(int argc, char* argv[]) {
    TEST(Operatory, WeryfikacjaAdresu) {
        std::array<std::array<std::string, 7>, 3> adresy_maski_podsieci_dobre =
        {
            std::array<std::string, 7> { "192.168.1.1", ..."}, // adresy_IP4_dobre
            std::array<std::string, 7> { "255.255.255.0", ..."}, // maski_IP4_dobre
            std::array<std::string, 7> { "192.168.1.0", ... "}, // podsieci_IP4_dobre
        };
        for (std::array<std::string, 7> adres_maska_podsiec : adresy_maski_podsieci_dobre) {
            for (std::string adres : adres_maska_podsiec) {
                EXPECT_TRUE(weryfikacja_wprowadzonych(adres)) << "Adres: " << adres << " powinien zostac uznany za poprawny";
            }
        }
    }
    return RUN_ALL_TESTS();
}
