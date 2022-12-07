#include "models/BankCard.h"
#include "models/Envelope.h"
#include "views/ConsoleView.h"
#include "presenter/Presenter.h"
#include "models/EFinanceStorageType.h"
#include "exceptions/WrongCardNumberException.h"


void TestModels()
{
    ConsoleView cw;

    try {
        BankCard* bc1 = new BankCard(EBankCardType::Debit, "123", "ВТБ", "", 10423.21);
        BankCard* bc2 = new BankCard(EBankCardType::Debit, "1234 1234 1234 1234", "Сбербанк", "", 15019.4);
        Envelope* e1 = new Envelope("Машина", "", 15008.542);
        FinanceStorage* fs[3] {bc1, bc2, e1};


        fs[0]->Transfer(1000, fs[1]);
        fs[0]->Refill(5000, fs[1]);
        fs[2]->Refill(3000, fs[1]);

        for (FinanceStorage* f: fs) {
            cw.Display(f->ToString());
        }

        delete(bc1);
        delete(bc2);
        delete(e1);
    } catch(WrongCardNumberException ex) {
        cw.Display(ex.what());
    }
}
void TestUI()
{
    Presenter* ui = new Presenter(new ConsoleView(), new std::vector<FinanceStorage*>());
    ui->Start();
    delete(ui);
}

int main() 
{
    // TestModels();
    TestUI();
}