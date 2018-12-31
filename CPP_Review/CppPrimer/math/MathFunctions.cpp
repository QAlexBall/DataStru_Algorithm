//
// Created by alex on 12/31/18.
//

double power(double base, int exponent)
{
    int result = static_cast<int>(base);
    int i;

    if (exponent == 0) {
        return 1;
    }

    for(i = 1; i < exponent; ++i){
        result = static_cast<int>(result * base);
    }

    return result;
}