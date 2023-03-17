//Denys Kyrychenko
#include <iostream>

int main() {
    unsigned int checksAmount, practicalGrade, bacaGrade;
    std::cin >> checksAmount;
    int idArray[checksAmount], gradeArray[checksAmount];
    
    for (int i = 0; i < checksAmount; i++) {
        std::cin >> idArray[i] >> practicalGrade >> bacaGrade;
        gradeArray[i] = practicalGrade + bacaGrade;
    }
    
    for (int i = 0; i < checksAmount; i++) {
        if (gradeArray[i] >= 90) {
            std::cout << idArray[i] << " " << gradeArray[i] << "%" << " bardzo dobry (5.0)" << std::endl;
        } else if (gradeArray[i] >= 80) {
            std::cout << idArray[i] << " " << gradeArray[i] << "%" << " dobry plus (4.5)" << std::endl;
        } else if (gradeArray[i] >= 70) {
            std::cout << idArray[i] << " " << gradeArray[i] << "%" << " dobry (4.0)" << std::endl;
        } else if (gradeArray[i] >= 60) {
            std::cout << idArray[i] << " " << gradeArray[i] << "%" << " dostateczny plus (3.5)" << std::endl;
        } else if (gradeArray[i] >= 50) {
            std::cout << idArray[i] << " " << gradeArray[i] << "%" << " dostateczny (3.0)" << std::endl;
        } else {
            std::cout << idArray[i] << " " << gradeArray[i] << "%" << " niedostateczny (2.0)" << std::endl;
        }
    }
    
    return 0;
}
