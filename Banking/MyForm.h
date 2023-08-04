#pragma once

#include <vector>
#include <string>

namespace BankingApp {

    using namespace System;
    using namespace System::Collections::Generic;
    using namespace System::Windows::Forms;

    public ref class MyForm : public Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~MyForm()
        {
            // Clean up resources here if needed.
        }

    private:
        System::Windows::Forms::Label^ lblAmount;
        System::Windows::Forms::Label^ lblAccountHolderName;
        System::Windows::Forms::Label^ lblAccountNumber;
        System::Windows::Forms::Label^ lblContactDetails;
        System::Windows::Forms::Button^ btnDeposit;
        System::Windows::Forms::Button^ btnWithdraw;
        System::Windows::Forms::Button^ btnViewBalance;
        System::Windows::Forms::Button^ btnAccountInfo;
        System::Windows::Forms::Button^ btnTransactionHistory;
        System::Windows::Forms::TextBox^ txtAmount;
        System::Windows::Forms::TextBox^ txtAccountHolderName;
        System::Windows::Forms::TextBox^ txtAccountNumber;
        System::Windows::Forms::TextBox^ txtContactDetails;

        // Your bank account variable to store the balance
        double accountBalance = 0.0;

        // Transaction history list
        List<String^> transactionHistory;

        // Function to deposit money
        void Deposit(double amount)
        {
            accountBalance += amount;
            UpdateTransactionHistory("Deposit", amount);
        }

        // Function to withdraw money
        bool Withdraw(double amount)
        {
            if (amount <= accountBalance)
            {
                accountBalance -= amount;
                UpdateTransactionHistory("Withdraw", amount);
                return true;
            }
            return false;
        }

        // Function to view account balance
        double ViewBalance()
        {
            return accountBalance;
        }

        // Function to update transaction history
        void UpdateTransactionHistory(String^ transactionType, double amount)
        {
            String^ transactionDetails = DateTime::Now.ToString() + " - " + transactionType + " $" + amount.ToString("F2");
            transactionHistory.Add(transactionDetails);
        }

        void InitializeComponent(void)
        {
            this->lblAmount = (gcnew System::Windows::Forms::Label());
            this->lblAccountHolderName = (gcnew System::Windows::Forms::Label());
            this->lblAccountNumber = (gcnew System::Windows::Forms::Label());
            this->lblContactDetails = (gcnew System::Windows::Forms::Label());
            this->btnDeposit = (gcnew System::Windows::Forms::Button());
            this->btnWithdraw = (gcnew System::Windows::Forms::Button());
            this->btnViewBalance = (gcnew System::Windows::Forms::Button());
            this->btnAccountInfo = (gcnew System::Windows::Forms::Button());
            this->btnTransactionHistory = (gcnew System::Windows::Forms::Button());
            this->txtAmount = (gcnew System::Windows::Forms::TextBox());
            this->txtAccountHolderName = (gcnew System::Windows::Forms::TextBox());
            this->txtAccountNumber = (gcnew System::Windows::Forms::TextBox());
            this->txtContactDetails = (gcnew System::Windows::Forms::TextBox());
            this->SuspendLayout();
            // 
            // lblAmount
            // 
            this->lblAmount->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->lblAmount->AutoSize = true;
            this->lblAmount->Font = (gcnew System::Drawing::Font(L"Stencil", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblAmount->ForeColor = System::Drawing::SystemColors::ActiveCaption;
            this->lblAmount->Location = System::Drawing::Point(2, 118);
            this->lblAmount->Name = L"lblAmount";
            this->lblAmount->Size = System::Drawing::Size(130, 32);
            this->lblAmount->TabIndex = 1;
            this->lblAmount->Text = L"Amount:";
            this->lblAmount->Click += gcnew System::EventHandler(this, &MyForm::lblAmount_Click);
            // 
            // lblAccountHolderName
            // 
            this->lblAccountHolderName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->lblAccountHolderName->AutoSize = true;
            this->lblAccountHolderName->Font = (gcnew System::Drawing::Font(L"Stencil", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblAccountHolderName->ForeColor = System::Drawing::SystemColors::ActiveCaption;
            this->lblAccountHolderName->Location = System::Drawing::Point(2, 16);
            this->lblAccountHolderName->Name = L"lblAccountHolderName";
            this->lblAccountHolderName->Size = System::Drawing::Size(331, 32);
            this->lblAccountHolderName->TabIndex = 8;
            this->lblAccountHolderName->Text = L"Account Holder Name:";
            this->lblAccountHolderName->Click += gcnew System::EventHandler(this, &MyForm::lblAccountHolderName_Click);
            // 
            // lblAccountNumber
            // 
            this->lblAccountNumber->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->lblAccountNumber->AutoSize = true;
            this->lblAccountNumber->Font = (gcnew System::Drawing::Font(L"Stencil", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblAccountNumber->ForeColor = System::Drawing::SystemColors::ActiveCaption;
            this->lblAccountNumber->Location = System::Drawing::Point(2, 72);
            this->lblAccountNumber->Name = L"lblAccountNumber";
            this->lblAccountNumber->Size = System::Drawing::Size(258, 32);
            this->lblAccountNumber->TabIndex = 9;
            this->lblAccountNumber->Text = L"Account Number:";
            this->lblAccountNumber->Click += gcnew System::EventHandler(this, &MyForm::lblAccountNumber_Click);
            // 
            // lblContactDetails
            // 
            this->lblContactDetails->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->lblContactDetails->AutoSize = true;
            this->lblContactDetails->Font = (gcnew System::Drawing::Font(L"Stencil", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblContactDetails->ForeColor = System::Drawing::SystemColors::ActiveCaption;
            this->lblContactDetails->Location = System::Drawing::Point(2, 165);
            this->lblContactDetails->Name = L"lblContactDetails";
            this->lblContactDetails->Size = System::Drawing::Size(253, 32);
            this->lblContactDetails->TabIndex = 10;
            this->lblContactDetails->Text = L"Contact Details:";
            this->lblContactDetails->Click += gcnew System::EventHandler(this, &MyForm::lblContactDetails_Click);
            // 
            // btnDeposit
            // 
            this->btnDeposit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->btnDeposit->AutoEllipsis = true;
            this->btnDeposit->AutoSize = true;
            this->btnDeposit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->btnDeposit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btnDeposit->Font = (gcnew System::Drawing::Font(L"Stencil", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnDeposit->Location = System::Drawing::Point(26, 383);
            this->btnDeposit->Name = L"btnDeposit";
            this->btnDeposit->Size = System::Drawing::Size(234, 44);
            this->btnDeposit->TabIndex = 2;
            this->btnDeposit->Text = L"Deposit";
            this->btnDeposit->UseVisualStyleBackColor = false;
            this->btnDeposit->UseWaitCursor = true;
            this->btnDeposit->Click += gcnew System::EventHandler(this, &MyForm::btnDeposit_Click);
            // 
            // btnWithdraw
            // 
            this->btnWithdraw->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->btnWithdraw->AutoEllipsis = true;
            this->btnWithdraw->AutoSize = true;
            this->btnWithdraw->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->btnWithdraw->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btnWithdraw->Font = (gcnew System::Drawing::Font(L"Stencil", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnWithdraw->Location = System::Drawing::Point(487, 383);
            this->btnWithdraw->Name = L"btnWithdraw";
            this->btnWithdraw->Size = System::Drawing::Size(237, 44);
            this->btnWithdraw->TabIndex = 3;
            this->btnWithdraw->Text = L"Withdraw";
            this->btnWithdraw->UseVisualStyleBackColor = false;
            this->btnWithdraw->UseWaitCursor = true;
            this->btnWithdraw->Click += gcnew System::EventHandler(this, &MyForm::btnWithdraw_Click);
            // 
            // btnViewBalance
            // 
            this->btnViewBalance->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->btnViewBalance->AutoEllipsis = true;
            this->btnViewBalance->AutoSize = true;
            this->btnViewBalance->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->btnViewBalance->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btnViewBalance->Font = (gcnew System::Drawing::Font(L"Stencil", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnViewBalance->Location = System::Drawing::Point(487, 314);
            this->btnViewBalance->Name = L"btnViewBalance";
            this->btnViewBalance->Size = System::Drawing::Size(237, 44);
            this->btnViewBalance->TabIndex = 4;
            this->btnViewBalance->Text = L"View Balance";
            this->btnViewBalance->UseVisualStyleBackColor = false;
            this->btnViewBalance->UseWaitCursor = true;
            this->btnViewBalance->Click += gcnew System::EventHandler(this, &MyForm::btnViewBalance_Click);
            // 
            // btnAccountInfo
            // 
            this->btnAccountInfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->btnAccountInfo->AutoEllipsis = true;
            this->btnAccountInfo->AutoSize = true;
            this->btnAccountInfo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->btnAccountInfo->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btnAccountInfo->Font = (gcnew System::Drawing::Font(L"Stencil", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnAccountInfo->Location = System::Drawing::Point(26, 314);
            this->btnAccountInfo->Name = L"btnAccountInfo";
            this->btnAccountInfo->Size = System::Drawing::Size(234, 44);
            this->btnAccountInfo->TabIndex = 5;
            this->btnAccountInfo->Text = L"Account Info";
            this->btnAccountInfo->UseVisualStyleBackColor = false;
            this->btnAccountInfo->UseWaitCursor = true;
            this->btnAccountInfo->Click += gcnew System::EventHandler(this, &MyForm::btnAccountInfo_Click);
            // 
            // btnTransactionHistory
            // 
            this->btnTransactionHistory->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->btnTransactionHistory->AutoEllipsis = true;
            this->btnTransactionHistory->AutoSize = true;
            this->btnTransactionHistory->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->btnTransactionHistory->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btnTransactionHistory->Font = (gcnew System::Drawing::Font(L"Stencil", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btnTransactionHistory->Location = System::Drawing::Point(180, 477);
            this->btnTransactionHistory->Name = L"btnTransactionHistory";
            this->btnTransactionHistory->Size = System::Drawing::Size(362, 44);
            this->btnTransactionHistory->TabIndex = 6;
            this->btnTransactionHistory->Text = L"Transaction History";
            this->btnTransactionHistory->UseVisualStyleBackColor = false;
            this->btnTransactionHistory->UseWaitCursor = true;
            this->btnTransactionHistory->Click += gcnew System::EventHandler(this, &MyForm::btnTransactionHistory_Click);
            // 
            // txtAmount
            // 
            this->txtAmount->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->txtAmount->Font = (gcnew System::Drawing::Font(L"Stencil", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txtAmount->Location = System::Drawing::Point(339, 118);
            this->txtAmount->Name = L"txtAmount";
            this->txtAmount->Size = System::Drawing::Size(385, 39);
            this->txtAmount->TabIndex = 7;
            this->txtAmount->TextChanged += gcnew System::EventHandler(this, &MyForm::txtAmount_TextChanged);
            // 
            // txtAccountHolderName
            // 
            this->txtAccountHolderName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->txtAccountHolderName->Font = (gcnew System::Drawing::Font(L"Stencil", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txtAccountHolderName->Location = System::Drawing::Point(339, 16);
            this->txtAccountHolderName->Name = L"txtAccountHolderName";
            this->txtAccountHolderName->Size = System::Drawing::Size(385, 39);
            this->txtAccountHolderName->TabIndex = 11;
            this->txtAccountHolderName->TextChanged += gcnew System::EventHandler(this, &MyForm::txtAccountHolderName_TextChanged);
            // 
            // txtAccountNumber
            // 
            this->txtAccountNumber->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->txtAccountNumber->Font = (gcnew System::Drawing::Font(L"Stencil", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txtAccountNumber->Location = System::Drawing::Point(339, 72);
            this->txtAccountNumber->Name = L"txtAccountNumber";
            this->txtAccountNumber->Size = System::Drawing::Size(385, 39);
            this->txtAccountNumber->TabIndex = 12;
            this->txtAccountNumber->TextChanged += gcnew System::EventHandler(this, &MyForm::txtAccountNumber_TextChanged);
            // 
            // txtContactDetails
            // 
            this->txtContactDetails->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
            this->txtContactDetails->Font = (gcnew System::Drawing::Font(L"Stencil", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->txtContactDetails->Location = System::Drawing::Point(339, 165);
            this->txtContactDetails->Name = L"txtContactDetails";
            this->txtContactDetails->Size = System::Drawing::Size(385, 39);
            this->txtContactDetails->TabIndex = 13;
            this->txtContactDetails->TextChanged += gcnew System::EventHandler(this, &MyForm::txtContactDetails_TextChanged_1);
            // 
            // MyForm
            // 
            this->BackColor = System::Drawing::Color::MidnightBlue;
            this->ClientSize = System::Drawing::Size(736, 641);
            this->Controls->Add(this->txtContactDetails);
            this->Controls->Add(this->txtAccountNumber);
            this->Controls->Add(this->txtAccountHolderName);
            this->Controls->Add(this->txtAmount);
            this->Controls->Add(this->btnTransactionHistory);
            this->Controls->Add(this->btnAccountInfo);
            this->Controls->Add(this->btnViewBalance);
            this->Controls->Add(this->btnWithdraw);
            this->Controls->Add(this->btnDeposit);
            this->Controls->Add(this->lblContactDetails);
            this->Controls->Add(this->lblAccountNumber);
            this->Controls->Add(this->lblAccountHolderName);
            this->Controls->Add(this->lblAmount);
            this->Font = (gcnew System::Drawing::Font(L"Stencil", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Name = L"MyForm";
            this->Text = L"Banking App";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load_1);
            this->ResumeLayout(false);
            this->PerformLayout();

        }

    private: // Add event handlers for the buttons
        System::Void btnDeposit_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Parse the amount from the text box
            double amount;
            if (Double::TryParse(txtAmount->Text, amount))
            {
                // Call the Deposit function and update the balance label
                Deposit(amount);
                txtAmount->Text = "";
            }
            else
            {
                MessageBox::Show("Invalid amount. Please enter a valid number.", "Error");
            }
        }

        System::Void btnWithdraw_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Parse the amount from the text box
            double amount;
            if (Double::TryParse(txtAmount->Text, amount))
            {
                // Call the Withdraw function and update the balance label
                if (Withdraw(amount))
                {
                    txtAmount->Text = "";
                }
                else
                {
                    MessageBox::Show("Insufficient funds. Cannot withdraw more than the account balance.", "Error");
                }
            }
            else
            {
                MessageBox::Show("Invalid amount. Please enter a valid number.", "Error");
            }
        }

        System::Void btnViewBalance_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Get the account balance
            double balance = ViewBalance();

            // Display the account balance as a pop-up message
            String^ message = "Account Balance: $" + balance.ToString("F2");
            MessageBox::Show(message, "Account Balance");
        }

        System::Void btnAccountInfo_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Get the account holder name, account number, and contact details
            String^ accountHolderName = txtAccountHolderName->Text;
            String^ accountNumber = txtAccountNumber->Text;
            String^ contactDetails = txtContactDetails->Text;

            // Display the account information as a pop-up message
            String^ accountInfo = "Account Holder Name: " + accountHolderName + "\nAccount Number: " + accountNumber + "\nContact Details: " + contactDetails;
            MessageBox::Show(accountInfo, "Account Information");
        }

        System::Void btnTransactionHistory_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Create a string to store the transaction history
            String^ history = "Transaction History:\n";

            // Loop through the transaction history list and add each entry to the string
            for (int i = 0; i < transactionHistory.Count; i++)
            {
                history += transactionHistory[i] + "\n";
            }

            // Display the transaction history as a pop-up message
            MessageBox::Show(history, "Transaction History");
        }

        System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
        }

        System::Void txtContactDetails_TextChanged(System::Object^ sender, System::EventArgs^ e) {
        }
    private: System::Void MyForm_Load_1(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void lblAmount_Click(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void lblAccountNumber_Click(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void lblContactDetails_Click(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void txtAccountHolderName_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void lblAccountHolderName_Click(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void txtAccountNumber_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void txtAmount_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void txtContactDetails_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
    }
};
}
