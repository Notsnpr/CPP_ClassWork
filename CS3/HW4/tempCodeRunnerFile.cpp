int main() {
    vector<double> data = {1.0, 2.5, 3.3, 4.8, 5.5, 6.7, 7.9};
    double targets[] = {1.0, 2.5, 3.3, 4.8, 5.5, 6.7, 7.9, 0.5, 8.0, 4.0, 6.7, 2.4};
    for (double t : targets) {
        int result = fastFind(data, t);
        if (result != -1)
            cout << "Found " << t << " at index " << result << endl;
        else
            cout << t << " not found" << endl;
    }
    return 0;
}