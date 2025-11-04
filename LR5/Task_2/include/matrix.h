#pragma once

void InvalidInput();
double RecursiveProduct(int* arr, int size);
void FillArray(int * arr, int size);
extern "C" void __attribute__((visibility("default"))) SolveTask();

const int kMaxSize = 10000;