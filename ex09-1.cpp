#include <iostream>
#include <string>
#include <vector>
struct Merchandise{
    std::string item;
    int price,qty;    
};

std::istream& operator>>(std::istream& in, Merchandise& m){
    return in >> m.item >> m.price >> m.qty;
}

std::ostream& operator<<(std::ostream& out, const Merchandise& m){
    return out << m.item << " " << m.price << " " << m.qty;
}

int main() {
    std::cout << "r: register, p: print" << std::endl;

    std::vector<Merchandise> ms;


    // 入力が失敗するまで一文字のコマンドを受け取るループを作成する
    for (char c; std::cin >> c;) {
        switch (c) {
            case 'r': { // rが入力された場合は商品の登録処理を行う
                std::cout << "item price qty: ";
                Merchandise m;

                // 商品名，単価，個数の情報を入力させる．入力が失敗した場合は登録処理を中断する
                if (!(std::cin >> m)) break;
                
                // 繰り返し処理を用いて登録されている商品名を探索する
                int i{};
                for (; i < ms.size(); ++i)
                    if (ms[i].item == m.item)
                        break;
                
                // 商品名が既に登録されていれば登録されている単価，個数の情報を新しい情報で更新する
                if (i < ms.size()) {
                    ms[i].price = m.price;
                    ms[i].qty = m.qty;
                    break;
                }

                // items，prices，qtiesに情報を追加する
                ms.push_back(m);
                break;
            }
            case 'p': { // pが入力された場合は注文票を出力する
                int total{};
                // 「商品名 単価 個数」を表示させる
                // さらに、totalを用いて合計金額を計算する
                for (int i{}; i < ms.size(); ++i) {
                    std::cout << ms[i] << std::endl;
                    total += ms[i].price * ms[i].qty;
                }

                std::cout << "total: " << total << std::endl;
                break;
            }
            default: // その他の文字が入力された場合は「Unknown command.」と出力する
                std::cout << "Unknown command." << std::endl;
        }
    }
}