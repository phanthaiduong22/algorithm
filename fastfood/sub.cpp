BigInt sub(BigInt a, BigInt b) {
    BigInt c;
    // số chữ số của c sẽ có thể nhỏ hơn hay bằng của a
    b.Digit.resize(a.Digit.size());
    c.Digit.resize(a.Digit.size());
    int leftover = 0;
    for (int i = 0; i < c.Digit.size(); i++) {
        leftover = a.Digit[i] - b.Digit[i] - leftover;
    if (leftover < 0) {
    // Nếu chữ số của số bị trừ nhỏ hơn số trừ, ta sẽ mượn 1
            c.Digit[i] = leftover + BASE;
            leftover = 1;
        }
    else {
    // Ngược lại, do là phép trừ thì phần dư của ta sẽ không bao giờ lớn hơn BASE
            c.Digit[i] = leftover;
            leftover = 0;
        }
    }
    // Khi trừ xong, ta sẽ kiểm tra và loại bỏ các số không vô nghĩa ở đầu
    while (c.Digit.size() >= 2 && c.Digit.back() == 0)
        c.Digit.pop_back();

    return c;
}
