#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>


// 構造体 Vector5D, 関数 operator>>, 関数 operator<<, 関数 operator< を実装してください
struct Vector5D
{
    std::string name;
    std::vector<double> elm = std::vector<double>(5);
    double norm{0};
};

std::istream& operator>>(std::istream& fin, Vector5D& v){
    fin >> v.name >> v.elm[0] >> v.elm[1] >> v.elm[2] >> v.elm[3] >> v.elm[4];
    double norm{};
    for (double i: v.elm) norm+=i*i;
    v.norm=sqrt(norm);
    return fin;
}

std::ostream& operator<<(std::ostream& out, const Vector5D& v){
    out << v.name << " (";
    for (int i=0; i<v.elm.size(); i++){
        out << v.elm[i];
        if (i<4) out << ", ";
        else out << ") ";
    }
    out << "norm: " << v.norm;
    return out;
}

bool operator<(const Vector5D& a,const Vector5D& b){
    return a.norm<b.norm;
}

int main() {
    
    // "struct_data_5d.dat"を読み込む
    std::ifstream fin( "struct_data_5d.dat" );
    if (!fin) {
        std::cerr << "cannot open\n";
        return 1;
    }
    std::vector<Vector5D> vs;
    for( Vector5D v; fin >> v; ) vs.push_back( v );
    std::cout << "n_vector: " << vs.size() << "\n";

    // 読み込んだベクトルを全て表示
    for( Vector5D v : vs ) std::cout << v << "\n";

    // 最も大きいノルムを持つベクトルを探索
    Vector5D largest = vs[0];
    for (size_t i = 1; i < vs.size(); i++) largest = largest < vs[i] ? vs[i] : largest;
    std::cout << "largest vector is: " << largest << "\n";

    return 0;
}
