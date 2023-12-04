    cout << "-------------------------------------------------------" << endl;
    cout <<setw(5) << "STT" << setw(10)<< "Ma ho so" << setw(18) << "Ho va ten" << setw(10) << "Luong" <<setw(20) <<"Xep loai" << endl;
    cout << "-------------------------------------------------------" << endl;
    for (int i = 0; i < n; ++i) {
        cout <<setw(5) << i + 1 << setw(10) << danhSach[i].getMaSo() << setw(20) << danhSach[i].getHoTen() << setw(10) << danhSach[i].getLuong() << setw(20) << danhSach[i].xepLoaiLuong() << endl;
    }
    cout << "-------------------------------------------------------" << endl;