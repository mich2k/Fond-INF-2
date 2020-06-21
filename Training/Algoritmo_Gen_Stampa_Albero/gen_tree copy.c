

void ricorsione(Node* n) {
    if (IsEmptyTree(n)) {
        return;
    }

    ricorsione(LeftTree(n));

    printf("\t %d", *GetRootValueTree(n));

    fflush(stdout);

    ricorsione(RightTree(n));
}