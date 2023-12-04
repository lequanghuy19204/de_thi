// Cho mô tả đối tượng NGƯỜI với các thông tin chính gồm: Mã số, Họ tên, Lương. Sử dụng phương pháp lập trình hướng đối tượng, xây dựng một chương trình với các nội dung sau:
// Câu 1: (2.0 điểm)
// Định nghĩa lớp đối tượng NGƯỜI trên với hàm tạo, hàm hủy và hâm nhập thông tin đối tượng.
// Câu 2: (2.0 điểm)
// Định nghĩa hàm thành phần Xếp loại Lương, nếu Lương < 5 triệu đồng trả về “Thu nhập thấp”, nếu 5 triệu đồng =< Lương < 10 triệu đồng trả về “Thu nhập trung bình", nếu 10 triều đồng =< Lương trả về “Thu nhập cao".
// Câu 3: (2.0 điểm)
// Định nghĩa toán tử so sánh ">" hai đối tượng, nếu Lương của đối tượng thứ nhất lớn hơn Lương của đối tương thứ hai trả về True, ngược lại trả về False.
// Câu 4: (2.0 điểm)
// Định nghĩa hai lớp dẫn xuất từ lớp đã được định nghĩa ở Câu 1 như sau:
// Lớp dẫn xuất thứ nhất: Giảng viên, Lương = Hệ số lương * Lương cơ bản +(Số tiết - 270)*90.000 + Phụ cấp.
// Lớp dẫn xuất thứ hai: Nhân viên hành chính, Lương = Hệ số lương * Lương cơ bản + Phụ cấp hành chính.
// Câu 5: (2,0 điểm)
// Tạo một danh sách nhân viên gồm n đối tượng (n<100.000), Nhập và in thông tin danh sách sắp xếp theo thứ tư a, b, c,... của Họ và tên theo mẫu định dạng sau: tạo ra 1 bảng cột 1 là STT, cột 2 là Mã hồ sơ, cột 3 là Họ và tên, cột 4 là Lương, cột 5 là Xếp loại

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

class NGUOI {
protected:
    string MaSo;
    string HoTen;
    double Luong;

public:
    NGUOI() {}
    NGUOI(string maSo, string hoTen, double luong) : MaSo(maSo), HoTen(hoTen), Luong(luong) {}
    virtual ~NGUOI() {}

    virtual void nhapThongTin() {
        cout << "Nhap Ma so: ";
        cin >> MaSo;
        cout << "Nhap Ho ten: ";
        cin.ignore();
        getline(cin, HoTen);
        cout << "Nhap Luong: ";
        cin >> Luong;
    }

    virtual string xepLoaiLuong() {
        if (Luong < 5000000)
            return "Thu nhap thap";
        else if (Luong < 10000000)
            return "Thu nhap trung binh";
        else
            return "Thu nhap cao";
    }

    bool operator>(const NGUOI &other) {
        return Luong > other.Luong;
    }

    string getMaSo() const {
        return MaSo;
    }

    string getHoTen() const {
        return HoTen;
    }

    double getLuong() const {
        return Luong;
    }
};

class GiangVien : public NGUOI {
private:
    double HeSoLuong;
    int SoTiet;
    double PhuCap;

public:
    GiangVien() {}
    GiangVien(string maSo, string hoTen, double luong, double heSoLuong, int soTiet, double phuCap)
        : NGUOI(maSo, hoTen, luong), HeSoLuong(heSoLuong), SoTiet(soTiet), PhuCap(phuCap) {}

    void nhapThongTin() override {
        NGUOI::nhapThongTin();
        cout << "Nhap He so luong: ";
        cin >> HeSoLuong;
        cout << "Nhap So tiet: ";
        cin >> SoTiet;
        cout << "Nhap Phu cap: ";
        cin >> PhuCap;
    }

    string xepLoaiLuong() override {
        double luong = HeSoLuong * Luong + (SoTiet - 270) * 90000 + PhuCap;
        Luong = luong; // Cập nhật lại lương
        return NGUOI::xepLoaiLuong();
    }
};

class NhanVienHanhChinh : public NGUOI {
private:
    double HeSoLuong;
    double PhuCapHanhChinh;

public:
    NhanVienHanhChinh() {}
    NhanVienHanhChinh(string maSo, string hoTen, double luong, double heSoLuong, double phuCapHanhChinh)
        : NGUOI(maSo, hoTen, luong), HeSoLuong(heSoLuong), PhuCapHanhChinh(phuCapHanhChinh) {}

    void nhapThongTin() override {
        NGUOI::nhapThongTin();
        cout << "Nhap He so luong: ";
        cin >> HeSoLuong;
        cout << "Nhap Phu cap hanh chinh: ";
        cin >> PhuCapHanhChinh;
    }

    string xepLoaiLuong() override {
        double luong = HeSoLuong * Luong + PhuCapHanhChinh;
        Luong = luong; // Cập nhật lại lương
        return NGUOI::xepLoaiLuong();
    }
};

void sapXepTheoTen(NGUOI **danhSach, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (danhSach[i]->getHoTen() > danhSach[j]->getHoTen()) {
                swap(danhSach[i], danhSach[j]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Nhap so luong nguoi: ";
    cin >> n;

    NGUOI **danhSach = new NGUOI*[n];

    for (int i = 0; i < n; ++i) {
        int choice;
        cout << "Nhap thong tin cho nguoi thu " << i + 1 << ":" << endl;
        cout << "1. Giang vien\n2. Nhan vien hanh chinh\nChon loai nguoi: ";
        cin >> choice;

        if (choice == 1) {
            GiangVien *gv = new GiangVien();
            gv->nhapThongTin();
            danhSach[i] = gv;
        } else if (choice == 2) {
            NhanVienHanhChinh *nv = new NhanVienHanhChinh();
            nv->nhapThongTin();
            danhSach[i] = nv;
        } else {
            cout << "Lua chon khong hop le." << endl;
            --i;
        }
    }

    sapXepTheoTen(danhSach, n);

    cout << "\nDanh sach nguoi sau khi sap xep theo ten:" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout <<setw(5) << "STT" << setw(10)<< "Ma ho so" << setw(18) << "Ho va ten" << setw(15) << "Luong" <<setw(25) <<"Xep loai" << endl;
    cout << "-------------------------------------------------------" << endl;
    for (int i = 0; i < n; ++i) {
        cout <<setw(5) << i + 1 << setw(10) << danhSach[i]->getMaSo() << setw(18) << danhSach[i]->getHoTen() << setw(15) << fixed << setprecision(2) << danhSach[i]->getLuong() << setw(25) << danhSach[i]->xepLoaiLuong() << endl;
    }
    cout << "-------------------------------------------------------" << endl;
    
    for (int i = 0; i < n; ++i) {
        delete danhSach[i];
    }
    delete[] danhSach;

    return 0;
}
