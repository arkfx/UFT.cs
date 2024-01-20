package com.example.entities;

interface Payment {
    void calculateInstallment();
    void calculatePayment();
    void recalculateInstallment();
    void pay();
    double fee = 0.0;
}






