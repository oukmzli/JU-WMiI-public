// Denys Kyrychenko
#include <iostream>
using namespace std;

int main() {
    int setAmount, i;
    double aResult = 0, bResult = 0, cResult = 0, dResult = 0, aDraws = 0, bDraws = 0, cDraws = 0, dDraws = 0, aSets = 0, bSets = 0, cSets = 0, dSets = 0;
    char jaszczurka = 'J', papier = 'P', kamien = 'K', nozyce = 'N', spock = 'S';
    
    char fPlayer, sPlayer, fChoice, sChoice;
    unsigned int fPower, sPower;
    
    i = 1;
    cin >> setAmount;
    if (setAmount != 0) {
        do {
            cin >> fPlayer >> fChoice >> fPower >> sPlayer >> sChoice >> sPower;
            if (fPlayer != sPlayer) {
                // jaszczurka
                if ((fChoice == jaszczurka && sChoice == papier) || (fChoice == jaszczurka && sChoice == spock)) {
                    if(fPlayer == 'a') { aResult++; aSets++; }
                    if(fPlayer == 'b') { bResult++; bSets++; }
                    if(fPlayer == 'c') { cResult++; cSets++; }
                    if(fPlayer == 'd') { dResult++; dSets++; }
                    
                    if(sPlayer == 'a') aSets++;
                    if(sPlayer == 'b') bSets++;
                    if(sPlayer == 'c') cSets++;
                    if(sPlayer == 'd') dSets++;
                } else if ((sChoice == jaszczurka && fChoice == papier) || (sChoice == jaszczurka && fChoice == spock)) {
                    if(sPlayer == 'a') { aResult++; aSets++; }
                    if(sPlayer == 'b') { bResult++; bSets++; }
                    if(sPlayer == 'c') { cResult++; cSets++; }
                    if(sPlayer == 'd') { dResult++; dSets++; }
                    
                    if(fPlayer == 'a') aSets++;
                    if(fPlayer == 'b') bSets++;
                    if(fPlayer == 'c') cSets++;
                    if(fPlayer == 'd') dSets++;
                }
                
                // kamien
                if ((fChoice == kamien && sChoice == jaszczurka) || (fChoice == kamien && sChoice == nozyce)) {
                    if(fPlayer == 'a') { aResult++; aSets++; }
                    if(fPlayer == 'b') { bResult++; bSets++; }
                    if(fPlayer == 'c') { cResult++; cSets++; }
                    if(fPlayer == 'd') { dResult++; dSets++; }
                    
                    if(sPlayer == 'a') aSets++;
                    if(sPlayer == 'b') bSets++;
                    if(sPlayer == 'c') cSets++;
                    if(sPlayer == 'd') dSets++;
                } else if ((sChoice == kamien && fChoice == jaszczurka) || (sChoice == kamien && fChoice == nozyce)) {
                    if(sPlayer == 'a') { aResult++; aSets++; }
                    if(sPlayer == 'b') { bResult++; bSets++; }
                    if(sPlayer == 'c') { cResult++; cSets++; }
                    if(sPlayer == 'd') { dResult++; dSets++; }
                    
                    if(fPlayer == 'a') aSets++;
                    if(fPlayer == 'b') bSets++;
                    if(fPlayer == 'c') cSets++;
                    if(fPlayer == 'd') dSets++;
                }
                
                // nozyce
                if ((fChoice == nozyce && sChoice == jaszczurka) || (fChoice == nozyce && sChoice == papier)) {
                    if(fPlayer == 'a') { aResult++; aSets++; }
                    if(fPlayer == 'b') { bResult++; bSets++; }
                    if(fPlayer == 'c') { cResult++; cSets++; }
                    if(fPlayer == 'd') { dResult++; dSets++; }
                    
                    if(sPlayer == 'a') aSets++;
                    if(sPlayer == 'b') bSets++;
                    if(sPlayer == 'c') cSets++;
                    if(sPlayer == 'd') dSets++;
                } else if ((sChoice == nozyce && fChoice == jaszczurka) || (sChoice == nozyce && fChoice == papier)) {
                    if(sPlayer == 'a') { aResult++; aSets++; }
                    if(sPlayer == 'b') { bResult++; bSets++; }
                    if(sPlayer == 'c') { cResult++; cSets++; }
                    if(sPlayer == 'd') { dResult++; dSets++; }
                    
                    if(fPlayer == 'a') aSets++;
                    if(fPlayer == 'b') bSets++;
                    if(fPlayer == 'c') cSets++;
                    if(fPlayer == 'd') dSets++;
                }
                
                // papier
                if ((fChoice == papier && sChoice == kamien) || (fChoice == papier && sChoice == spock)) {
                    if(fPlayer == 'a') { aResult++; aSets++; }
                    if(fPlayer == 'b') { bResult++; bSets++; }
                    if(fPlayer == 'c') { cResult++; cSets++; }
                    if(fPlayer == 'd') { dResult++; dSets++; }
                    
                    if(sPlayer == 'a') aSets++;
                    if(sPlayer == 'b') bSets++;
                    if(sPlayer == 'c') cSets++;
                    if(sPlayer == 'd') dSets++;
                } else if ((sChoice == papier && fChoice == kamien) || (sChoice == papier && fChoice == spock)) {
                    if(sPlayer == 'a') { aResult++; aSets++; }
                    if(sPlayer == 'b') { bResult++; bSets++; }
                    if(sPlayer == 'c') { cResult++; cSets++; }
                    if(sPlayer == 'd') { dResult++; dSets++; }
                    
                    if(fPlayer == 'a') aSets++;
                    if(fPlayer == 'b') bSets++;
                    if(fPlayer == 'c') cSets++;
                    if(fPlayer == 'd') dSets++;
                }
                
                // spock
                if ((fChoice == spock && sChoice == kamien) || (fChoice == spock && sChoice == nozyce)) {
                    if(fPlayer == 'a') { aResult++; aSets++; }
                    if(fPlayer == 'b') { bResult++; bSets++; }
                    if(fPlayer == 'c') { cResult++; cSets++; }
                    if(fPlayer == 'd') { dResult++; dSets++; }
                    
                    if(sPlayer == 'a') aSets++;
                    if(sPlayer == 'b') bSets++;
                    if(sPlayer == 'c') cSets++;
                    if(sPlayer == 'd') dSets++;
                } else if ((sChoice == spock && fChoice == kamien) || (sChoice == spock && fChoice == nozyce)) {
                    if(sPlayer == 'a') { aResult++; aSets++; }
                    if(sPlayer == 'b') { bResult++; bSets++; }
                    if(sPlayer == 'c') { cResult++; cSets++; }
                    if(sPlayer == 'd') { dResult++; dSets++; }
                    
                    if(fPlayer == 'a') aSets++;
                    if(fPlayer == 'b') bSets++;
                    if(fPlayer == 'c') cSets++;
                    if(fPlayer == 'd') dSets++;
                }
                
                // remisy
                if (fChoice == sChoice) {
                    if (fPower > sPower) {
                        if(fPlayer == 'a') { aResult++; aSets++; }
                        if(fPlayer == 'b') { bResult++; bSets++; }
                        if(fPlayer == 'c') { cResult++; cSets++; }
                        if(fPlayer == 'd') { dResult++; dSets++; }
                        
                        if(sPlayer == 'a') aSets++;
                        if(sPlayer == 'b') bSets++;
                        if(sPlayer == 'c') cSets++;
                        if(sPlayer == 'd') dSets++;
                    } else if (sPower > fPower) {
                        if(sPlayer == 'a') { aResult++; aSets++; }
                        if(sPlayer == 'b') { bResult++; bSets++; }
                        if(sPlayer == 'c') { cResult++; cSets++; }
                        if(sPlayer == 'd') { dResult++; dSets++; }
                        
                        if(fPlayer == 'a') aSets++;
                        if(fPlayer == 'b') bSets++;
                        if(fPlayer == 'c') cSets++;
                        if(fPlayer == 'd') dSets++;
                    } else {
                        if(fPlayer == 'a') { aDraws++; aSets++; }
                        if(fPlayer == 'b') { bDraws++; bSets++; }
                        if(fPlayer == 'c') { cDraws++; cSets++; }
                        if(fPlayer == 'd') { dDraws++; dSets++; }
                        
                        if(sPlayer == 'a') { aDraws++; aSets++; }
                        if(sPlayer == 'b') { bDraws++; bSets++; }
                        if(sPlayer == 'c') { cDraws++; cSets++; }
                        if(sPlayer == 'd') { dDraws++; dSets++; }
                    }
                }
            } else {
                if(fPlayer == 'a') { aDraws = aDraws; aSets = aSets; }
                if(fPlayer == 'b') { bDraws = bDraws; bSets = bSets; }
                if(fPlayer == 'c') { cDraws = cDraws; cSets = cSets; }
                if(fPlayer == 'd') { dDraws = dDraws; dSets = dSets; }
            }
        } while (++i <= setAmount);
    }
    
    double aLoose = aSets - (aResult + aDraws);
    double bLoose = bSets - (bResult + bDraws);
    double cLoose = cSets - (cResult + cDraws);
    double dLoose = dSets - (dResult + dDraws);
    
    // player a
    if (aSets > 0) {
        cout << "gracz a\n";
        if (aResult > 0) cout << "\twygrane: " << (aResult / aSets) * 100 << "%\n";
        if (aDraws > 0) cout << "\tremisy: " << (aDraws / aSets) * 100 << "%\n";
        if (aLoose > 0) cout << "\tprzegrane: " << (aLoose / aSets) * 100 << "%\n";
        if (bSets > 0 || cSets > 0 || dSets > 0) cout << endl;
    }
    
    // player b
    if (bSets > 0) {
        cout << "gracz b\n";
        if (bResult > 0) cout << "\twygrane: " << (bResult / bSets) * 100 << "%\n";
        if (bDraws > 0) cout << "\tremisy: " << (bDraws / bSets) * 100 << "%\n";
        if (bLoose > 0) cout << "\tprzegrane: " << (bLoose / bSets) * 100 << "%\n";
        if (cSets > 0 || dSets > 0) cout << endl;
    }
    
    //player c
    if (cSets > 0) {
        cout << "gracz c\n";
        if (cResult > 0) cout << "\twygrane: " << (cResult / cSets) * 100 << "%\n";
        if (cDraws > 0) cout << "\tremisy: " << (cDraws / cSets) * 100 << "%\n";
        if (cLoose > 0) cout << "\tprzegrane: " << (cLoose / cSets) * 100 << "%\n";
        if (dSets > 0) cout << endl;
    }
    
    //player d
    if (dSets > 0) {
        cout << "gracz d\n";
        if (dResult > 0) cout << "\twygrane: " << (dResult / dSets) * 100 << "%\n";
        if (dDraws > 0) cout << "\tremisy: " << (dDraws / dSets) * 100 << "%\n";
        if (dLoose > 0) cout << "\tprzegrane: " << (dLoose / dSets) * 100 << "%\n";
    }
    
    return 0;
}
