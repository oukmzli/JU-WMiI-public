// Denys Kyrychenko
#include <iostream>
using namespace std;

bool charEquality (char *a, char *b) {
    for (int i = 0; (a[i] != '\0') || (b[i] != '\0'); ++i)
        if (a[i] != b[i]) return false;
    return true;
}

struct Place {
    unsigned short ware;
    unsigned char label[2];
};

struct Shelf {
    Place place[128];
    int placesAmount;
};

struct Rack {
    Shelf shelf[128];
    int shelvesAmount;
};

struct Warehouse {
    Shelf hadnyShelf;
    
    Rack rack[128];
    int racksAmount;
};

struct Storehouse {
    Rack handyRack;
    Shelf handyShelf;
    
    Warehouse warehouse[128];
    int warehousesAmount;
    
    unsigned long eSum;
    unsigned long rhSum;
    unsigned long sSum;
};

Storehouse storehouse;

void setAP (Storehouse &storhouse, int wb, int rb, int sb, int pe) {
    int previousAmount = storehouse.warehouse[wb].rack[rb].shelf[sb].placesAmount;
    storehouse.warehouse[wb].rack[rb].shelf[sb].placesAmount = pe;
    
    for (int i = previousAmount; i < pe; ++i) {
        storehouse.warehouse[wb].rack[rb].shelf[sb].place[i].ware = 0;
        storehouse.warehouse[wb].rack[rb].shelf[sb].place[i].label[0] = '0';
        storehouse.warehouse[wb].rack[rb].shelf[sb].place[i].label[1] = '0';
    }
    
    for (int i = pe; i < 128; ++i) {
        storehouse.eSum -= storehouse.warehouse[wb].rack[rb].shelf[sb].place[i].ware;
        
        storehouse.warehouse[wb].rack[rb].shelf[sb].place[i].ware = 0;
        storehouse.warehouse[wb].rack[rb].shelf[sb].place[i].label[0] = '\0';
        storehouse.warehouse[wb].rack[rb].shelf[sb].place[i].label[1] = '\0';
    }
}

void setAS (Storehouse &storehouse, int wb, int rb, int se, int pe) {
    int previousAmount = storehouse.warehouse[wb].rack[rb].shelvesAmount;
    storehouse.warehouse[wb].rack[rb].shelvesAmount = se;
    
    for (int i = previousAmount; i < se; ++i) {
        storehouse.warehouse[wb].rack[rb].shelf[i].placesAmount = pe;
        for (int j = 0; j < pe; ++j) {
            storehouse.warehouse[wb].rack[rb].shelf[i].place[j].ware = 0;
            storehouse.warehouse[wb].rack[rb].shelf[i].place[j].label[0] = '\0';
            storehouse.warehouse[wb].rack[rb].shelf[i].place[j].label[1] = '\0';
        }
    }
    
    for (int i = se; i < 128; ++i) {
        for (int j = 0; j < storehouse.warehouse[wb].rack[rb].shelf[i].placesAmount; ++j) {
            storehouse.eSum -= storehouse.warehouse[wb].rack[rb].shelf[i].place[j].ware;
            
            storehouse.warehouse[wb].rack[rb].shelf[i].place[j].ware = 0;
            storehouse.warehouse[wb].rack[rb].shelf[i].place[j].label[0] = '\0';
            storehouse.warehouse[wb].rack[rb].shelf[i].place[j].label[1] = '\0';
        }
        storehouse.warehouse[wb].rack[rb].shelf[i].placesAmount = 0;
    }
    
    if (previousAmount < se) {
        for (int i = 0; i < previousAmount; ++i)
            setAP(storehouse, wb, rb, i, pe);
    } else {
        for (int i = 0; i < se; ++i)
            setAP(storehouse, wb, rb, i, pe);
    }
}

void setAR (Storehouse &storehouse, int wb, int re, int se, int pe) {
    int previousAmount = storehouse.warehouse[wb].racksAmount;
    storehouse.warehouse[wb].racksAmount = re;
    
    for (int i = previousAmount; i < re; ++i) {
        storehouse.warehouse[wb].rack[i].shelvesAmount = se;
        for (int j = 0; j < se; ++j) {
            storehouse.warehouse[wb].rack[i].shelf[j].placesAmount = pe;
            for (int k = 0; k < pe; ++k) {
                storehouse.warehouse[wb].rack[i].shelf[j].place[k].ware = 0;
                storehouse.warehouse[wb].rack[i].shelf[j].place[k].label[0] = '\0';
                storehouse.warehouse[wb].rack[i].shelf[j].place[k].label[1] = '\0';
            }
        }
    }
    
    for (int i = re; i < 128; ++i) {
        for (int j = 0; j < storehouse.warehouse[wb].rack[i].shelvesAmount; ++j) {
            for (int k = 0; k < storehouse.warehouse[wb].rack[i].shelf[j].placesAmount; ++k) {
                storehouse.eSum -= storehouse.warehouse[wb].rack[i].shelf[j].place[k].ware;
                
                storehouse.warehouse[wb].rack[i].shelf[j].place[k].ware = 0;
                storehouse.warehouse[wb].rack[i].shelf[j].place[k].label[0] = '\0';
                storehouse.warehouse[wb].rack[i].shelf[j].place[k].label[1] = '\0';
            }
            storehouse.warehouse[wb].rack[i].shelf[j].placesAmount = 0;
        }
        storehouse.warehouse[wb].rack[i].shelvesAmount = 0;
    }
    
    if (previousAmount < re) {
        for (int i = 0; i < previousAmount; ++i)
            setAS(storehouse, wb, i, se, pe);
    } else {
        for (int i = 0; i < re; ++i)
            setAS(storehouse, wb, i, se, pe);
    }
}

void setAW (Storehouse &storehouse, int we, int re, int se, int pe) {
    int previousAmount = storehouse.warehousesAmount;
    storehouse.warehousesAmount = we;
    
    for (int i = previousAmount; i < we; ++i) {
        storehouse.warehouse[i].racksAmount = re;
        for (int j = 0; j < re; ++j) {
            storehouse.warehouse[i].rack[j].shelvesAmount = se;
            for (int k = 0; k < se; ++k) {
                storehouse.warehouse[i].rack[j].shelf[k].placesAmount = pe;
                for (int l = 0; l < pe; ++l) {
                    storehouse.warehouse[i].rack[j].shelf[k].place[l].ware = 0;
                    storehouse.warehouse[i].rack[j].shelf[k].place[l].label[0] = '\0';
                    storehouse.warehouse[i].rack[j].shelf[k].place[l].label[1] = '\0';
                }
            }
        }
    }
    
    for (int i = we; i < 128; ++i) {
        storehouse.warehouse[i].hadnyShelf.placesAmount = 0;
        for (int j = 0; j < storehouse.warehouse[i].racksAmount; ++j) {
            for (int k = 0; k < storehouse.warehouse[i].rack[j].shelvesAmount; ++k) {
                for (int l = 0; l < storehouse.warehouse[i].rack[j].shelf[k].placesAmount; ++l) {
                    storehouse.eSum -= storehouse.warehouse[i].rack[j].shelf[k].place[l].ware;
                    
                    storehouse.warehouse[i].rack[j].shelf[k].place[l].ware = 0;
                    storehouse.warehouse[i].rack[j].shelf[k].place[l].label[0] = '\0';
                    storehouse.warehouse[i].rack[j].shelf[k].place[l].label[1] = '\0';
                    
                    storehouse.eSum -= storehouse.warehouse[i].hadnyShelf.place[l].ware;
                    storehouse.warehouse[i].hadnyShelf.place[l].ware = 0;
                    storehouse.warehouse[i].hadnyShelf.place[l].label[0] = '\0';
                    storehouse.warehouse[i].hadnyShelf.place[l].label[1] = '\0';
                }
                storehouse.warehouse[i].rack[j].shelf[k].placesAmount = 0;
            }
            storehouse.warehouse[i].rack[j].shelvesAmount = 0;
        }
        storehouse.warehouse[i].racksAmount = 0;
        storehouse.warehouse[i].hadnyShelf.placesAmount = 0;
    }
    
    if (previousAmount < we) {
        for (int i = 0; i < previousAmount; ++i)
            setAR(storehouse, i, re, se, pe);
    } else {
        for (int i = 0; i < we; ++i)
            setAR(storehouse, i, re, se, pe);
    }
}

void setHW (Storehouse &storehouse, int w, int p) {
    int previousAmount = storehouse.warehouse[w].hadnyShelf.placesAmount;
    storehouse.warehouse[w].hadnyShelf.placesAmount = p;
    
    for (int i = previousAmount; i < p; ++i) {
        storehouse.warehouse[w].hadnyShelf.place[i].ware = 0;
        storehouse.warehouse[w].hadnyShelf.place[i].label[0] = '0';
        storehouse.warehouse[w].hadnyShelf.place[i].label[1] = '0';
    }
    
    for (int i = p; i < 128; ++i) {
        storehouse.eSum -= storehouse.warehouse[w].hadnyShelf.place[i].ware;
        
        storehouse.warehouse[w].hadnyShelf.place[i].ware = 0;
        storehouse.warehouse[w].hadnyShelf.place[i].label[0] = '\0';
        storehouse.warehouse[w].hadnyShelf.place[i].label[1] = '\0';
    }
}

void setHP (Storehouse &storhouse, int s, int p) {
    int previousAmount = storehouse.handyRack.shelf[s].placesAmount;
    storehouse.handyRack.shelf[s].placesAmount = p;
    
    for (int i = previousAmount; i < p; ++i) {
        storehouse.handyRack.shelf[s].place[i].ware = 0;
        storehouse.handyRack.shelf[s].place[i].label[0] = '0';
        storehouse.handyRack.shelf[s].place[i].label[1] = '0';
    }
    
    for (int i = p; i < 128; ++i) {
        storehouse.eSum -= storehouse.handyRack.shelf[s].place[i].ware;
        storehouse.rhSum -= storehouse.handyRack.shelf[s].place[i].ware;
        
        storehouse.handyRack.shelf[s].place[i].ware = 0;
        storehouse.handyRack.shelf[s].place[i].label[0] = '\0';
        storehouse.handyRack.shelf[s].place[i].label[1] = '\0';
    }
}

void setHR (Storehouse &storehouse, int s, int p) {
    int previousAmount = storehouse.handyRack.shelvesAmount;
    storehouse.handyRack.shelvesAmount = s;
    
    for (int i = previousAmount; i < s; ++i) {
        storehouse.handyRack.shelf[i].placesAmount = p;
        for (int j = 0; j < p; ++j) {
            storehouse.handyRack.shelf[i].place[j].ware = 0;
            storehouse.handyRack.shelf[i].place[j].label[0] = '0';
            storehouse.handyRack.shelf[i].place[j].label[1] = '0';
        }
    }
    
    
    for (int i = s; i < 128; ++i) {
        for (int j = 0; j < storehouse.handyRack.shelf[i].placesAmount; ++j) {
            storehouse.eSum -= storehouse.handyRack.shelf[i].place[j].ware;
            storehouse.rhSum -= storehouse.handyRack.shelf[i].place[j].ware;
            
            storehouse.handyRack.shelf[i].place[j].ware = 0;
            storehouse.handyRack.shelf[i].place[j].label[0] = '\0';
            storehouse.handyRack.shelf[i].place[j].label[1] = '\0';
        }
        storehouse.handyRack.shelf[i].placesAmount = 0;
    }
    
    for (int i = 0; i < previousAmount; ++i) {
        int previousHandyShelf = storehouse.handyRack.shelf[i].placesAmount;
        storehouse.handyRack.shelf[i].placesAmount = p;
        
        for (int j = previousHandyShelf; j < p; ++j) {
            storehouse.handyRack.shelf[i].place[j].ware = 0;
            storehouse.handyRack.shelf[i].place[j].label[0] = '0';
            storehouse.handyRack.shelf[i].place[j].label[1] = '0';
        }
        
        for (int j = p; j < 128; ++j) {
            storehouse.eSum -= storehouse.handyRack.shelf[i].place[j].ware;
            storehouse.rhSum -= storehouse.handyRack.shelf[i].place[j].ware;
            
            storehouse.handyRack.shelf[i].place[j].ware = 0;
            storehouse.handyRack.shelf[i].place[j].label[0] = '\0';
            storehouse.handyRack.shelf[i].place[j].label[1] = '\0';
        }
    }
}

void setHS (Storehouse &storehouse, int p) {
    int previousAmount = storehouse.handyShelf.placesAmount;
    storehouse.handyShelf.placesAmount = p;
    
    for (int i = previousAmount; i < p; ++i) {
        storehouse.handyShelf.place[i].ware = 0;
        storehouse.handyShelf.place[i].label[0] = '0';
        storehouse.handyShelf.place[i].label[1] = '0';
    }
    
    for (int i = p; i < 128; ++i) {
        storehouse.eSum -= storehouse.handyShelf.place[i].ware;
        storehouse.sSum -= storehouse.handyShelf.place[i].ware;
        
        storehouse.handyShelf.place[i].ware = 0;
        storehouse.handyShelf.place[i].label[0] = '\0';
        storehouse.handyShelf.place[i].label[1] = '\0';
    }
}

void fill (Storehouse &storehouse, int w, int r, int s, int p, unsigned short a) {
    storehouse.eSum = 0;
    storehouse.rhSum = 0;
    storehouse.sSum = 0;
    
    storehouse.handyShelf.placesAmount = p;
    storehouse.handyRack.shelvesAmount = s;
    storehouse.warehousesAmount = w;
    
    for (int i = 0; i < storehouse.warehousesAmount; ++i) {
        storehouse.warehouse[i].racksAmount = r;
        storehouse.warehouse[i].hadnyShelf.placesAmount = p;
        
        for (int j = 0; j < r; ++j) {
            storehouse.warehouse[i].rack[j].shelvesAmount = s;
            
            for (int k = 0; k < s; ++k) {
                storehouse.warehouse[i].rack[j].shelf[k].placesAmount = p;
                
                if (!i && !j) storehouse.handyRack.shelf[k].placesAmount = p;
                
                for (int l = 0; l < p; ++l) {
                    storehouse.eSum += a;
                    
                    storehouse.warehouse[i].rack[j].shelf[k].place[l].ware = a;
                    storehouse.warehouse[i].rack[j].shelf[k].place[l].label[0] = '\0';
                    storehouse.warehouse[i].rack[j].shelf[k].place[l].label[1] = '\0';
                    
                    if (!j && !i) {
                        storehouse.eSum += a;
                        storehouse.rhSum += a;
                        
                        storehouse.handyRack.shelf[k].place[l].ware = a;
                        storehouse.handyRack.shelf[k].place[l].label[0] = '\0';
                        storehouse.handyRack.shelf[k].place[l].label[1] = '\0';
                    }
                    if (!k && !j) {
                        storehouse.eSum += a;
                        
                        storehouse.warehouse[i].hadnyShelf.place[l].ware = a;
                        storehouse.warehouse[i].hadnyShelf.place[l].label[0] = '\0';
                        storehouse.warehouse[i].hadnyShelf.place[l].label[1] = '\0';
                    }
                    if (!k && !j && !i) {
                        storehouse.eSum += a;
                        storehouse.sSum += a;
                        
                        storehouse.handyShelf.place[l].ware = a;
                        storehouse.handyShelf.place[l].label[0] = '\0';
                        storehouse.handyShelf.place[l].label[1] = '\0';
                    }
                }
            }
        }
    }
    
    bool fi = 1, fj = 1, fk = 1;
    
    for (int i = 127; i >= w; --i) {
        storehouse.warehouse[i].racksAmount = 0;
        storehouse.warehouse[i].hadnyShelf.placesAmount = 0;
        
        fj = 1;
        for (int j = 127; j >= r; --j) {
            storehouse.warehouse[i].rack[j].shelvesAmount = 0;
            
            fk = 1;
            for (int k = 127; k >= s; --k) {
                storehouse.warehouse[i].rack[j].shelf[k].placesAmount = 0;
                
                for (int l = 127; l >= p; --l) {
                    storehouse.warehouse[i].rack[j].shelf[k].place[l].ware = 0;
                    storehouse.warehouse[i].rack[j].shelf[k].place[l].label[0] = '\0';
                    storehouse.warehouse[i].rack[j].shelf[k].place[l].label[1] = '\0';
                    
                    if (fj && fi) {
                        storehouse.handyRack.shelf[k].place[l].ware = 0;
                        storehouse.handyRack.shelf[k].place[l].label[0] = '\0';
                        storehouse.handyRack.shelf[k].place[l].label[1] = '\0';
                    }
                    if (fk && fj) {
                        storehouse.warehouse[i].hadnyShelf.place[l].ware = 0;
                        storehouse.warehouse[i].hadnyShelf.place[l].label[0] = '\0';
                        storehouse.warehouse[i].hadnyShelf.place[l].label[1] = '\0';
                    }
                    if (fk && fj && fi) {
                        storehouse.handyShelf.place[l].ware = 0;
                        storehouse.handyShelf.place[l].label[0] = '\0';
                        storehouse.handyShelf.place[l].label[1] = '\0';
                    }
                }
                fk = 0;
            }
            fj = 0;
        }
        fi = 0;
    }
}

unsigned long getE (Storehouse &storehouse) { return storehouse.eSum; }

unsigned long getW (Storehouse &storehouse, int w) {
    unsigned long sum = 0;
    for (int i = 0; i < storehouse.warehouse[w].racksAmount; ++i)
        for (int j = 0; j < storehouse.warehouse[w].rack[i].shelvesAmount; ++j)
            for (int k = 0; k < storehouse.warehouse[w].rack[i].shelf[j].placesAmount; ++k) {
                sum += storehouse.warehouse[w].rack[i].shelf[j].place[k].ware;
            }
    for (int i = 0; i < storehouse.warehouse[w].hadnyShelf.placesAmount; ++i) {
        sum += storehouse.warehouse[w].hadnyShelf.place[i].ware;
    }
    return sum;
}

unsigned long getRW (Storehouse &storehouse, int w, int r) {
    unsigned long sum = 0;
    for (int i = 0; i < storehouse.warehouse[w].rack[r].shelvesAmount; ++i)
        for (int j = 0; j < storehouse.warehouse[w].rack[r].shelf[i].placesAmount; ++j)
            sum += storehouse.warehouse[w].rack[r].shelf[i].place[j].ware;
    return sum;
}

unsigned long getRH (Storehouse &storehouse) { return storehouse.rhSum; }

unsigned long getSW (Storehouse &storehouse, int w, int r, int s) {
    unsigned long sum = 0;
    for (int i = 0; i < storehouse.warehouse[w].rack[r].shelf[s].placesAmount; ++i)
        sum += storehouse.warehouse[w].rack[r].shelf[s].place[i].ware;
    return sum;
}

unsigned long getSH (Storehouse &storehouse, int w) {
    unsigned long sum = 0;
    for (int i = 0; i < storehouse.warehouse[w].hadnyShelf.placesAmount; ++i)
        sum += storehouse.warehouse[w].hadnyShelf.place[i].ware;
    return sum;
}

unsigned long getSR (Storehouse &storehouse, int s) {
    unsigned long sum = 0;
    for (int i = 0; i < storehouse.handyRack.shelf[s].placesAmount; ++i)
        sum += storehouse.handyRack.shelf[s].place[i].ware;
    return sum;
}

unsigned long getS (Storehouse &storehouse) { return storehouse.sSum; }

void putW (Storehouse &storehouse, int w, int r, int s, int p, int a) {
    if ((storehouse.warehouse[w].rack[r].shelf[s].place[p].ware + a) >= 65535) {
        storehouse.eSum += 65535 - storehouse.warehouse[w].rack[r].shelf[s].place[p].ware;
        storehouse.warehouse[w].rack[r].shelf[s].place[p].ware = 65535;
    }
    else {
        storehouse.eSum += a;
        storehouse.warehouse[w].rack[r].shelf[s].place[p].ware += a;
    }
}

void putH (Storehouse &storehouse, int w, int p, int a) {
    if ((storehouse.warehouse[w].hadnyShelf.place[p].ware + a) >= 65535) {
        storehouse.eSum += 65535 - storehouse.warehouse[w].hadnyShelf.place[p].ware;
        storehouse.warehouse[w].hadnyShelf.place[p].ware = 65535;
    }
    else {
        storehouse.eSum += a;
        storehouse.warehouse[w].hadnyShelf.place[p].ware += a;
    }
}

void putR (Storehouse &storehouse, int s, int p, int a) {
    if ((storehouse.handyRack.shelf[s].place[p].ware + a) >= 65535) {
        storehouse.eSum += 65535 - storehouse.handyRack.shelf[s].place[p].ware;
        storehouse.rhSum += 65535 - storehouse.handyRack.shelf[s].place[p].ware;
        storehouse.handyRack.shelf[s].place[p].ware = 65535;
    }
    else {
        storehouse.eSum += a;
        storehouse.rhSum += a;
        storehouse.handyRack.shelf[s].place[p].ware += a;
    }
}

void putS (Storehouse &storehouse, int p, int a) {
    if ((storehouse.handyShelf.place[p].ware + a) >= 65535) {
        storehouse.eSum += 65535 - storehouse.handyShelf.place[p].ware;
        storehouse.sSum += 65535 - storehouse.handyShelf.place[p].ware;
        storehouse.handyShelf.place[p].ware = 65535;
    }
    else {
        storehouse.eSum += a;
        storehouse.sSum += a;
        storehouse.handyShelf.place[p].ware += a;
    }
}

void popW (Storehouse &storehouse, int w, int r, int s, int p, int a) {
    if ((storehouse.warehouse[w].rack[r].shelf[s].place[p].ware - a) <= 0) {
        storehouse.eSum -= storehouse.warehouse[w].rack[r].shelf[s].place[p].ware;
        storehouse.warehouse[w].rack[r].shelf[s].place[p].ware = 0;
    }
    else {
        storehouse.eSum -= a;
        storehouse.warehouse[w].rack[r].shelf[s].place[p].ware -= a;
    }
}

void popH (Storehouse &storehouse, int w, int p, int a) {
    if ((storehouse.warehouse[w].hadnyShelf.place[p].ware - a) <= 0) {
        storehouse.eSum -= storehouse.warehouse[w].hadnyShelf.place[p].ware;
        storehouse.warehouse[w].hadnyShelf.place[p].ware = 0;
    }
    else {
        storehouse.eSum -= a;
        storehouse.warehouse[w].hadnyShelf.place[p].ware -= a;
    }
}

void popR (Storehouse &storehouse, int s, int p, int a) {
    if ((storehouse.handyRack.shelf[s].place[p].ware - a) <= 0) {
        storehouse.eSum -= storehouse.handyRack.shelf[s].place[p].ware;
        storehouse.rhSum -= storehouse.handyRack.shelf[s].place[p].ware;
        storehouse.handyRack.shelf[s].place[p].ware = 0;
    }
    else {
        storehouse.eSum -= a;
        storehouse.rhSum -= a;
        storehouse.handyRack.shelf[s].place[p].ware -= a;
    }
}

void popS (Storehouse &storehouse, int p, int a) {
    if ((storehouse.handyShelf.place[p].ware - a) <= 0) {
        storehouse.eSum -= storehouse.handyShelf.place[p].ware;
        storehouse.sSum -= storehouse.handyShelf.place[p].ware;
        storehouse.handyShelf.place[p].ware = 0;
    }
    else {
        storehouse.eSum -= a;
        storehouse.sSum -= a;
        storehouse.handyShelf.place[p].ware -= a;
    }
}

void setLW (Storehouse &storehouse, int w, int r, int s, int p, unsigned char dd[2]) {
    storehouse.warehouse[w].rack[r].shelf[s].place[p].label[0] = dd[0];
    storehouse.warehouse[w].rack[r].shelf[s].place[p].label[1] = dd[1];
}

void setLH (Storehouse &storehouse, int w, int p, unsigned char dd[2]) {
    storehouse.warehouse[w].hadnyShelf.place[p].label[0] = dd[0];
    storehouse.warehouse[w].hadnyShelf.place[p].label[1] = dd[1];
}

void setLR (Storehouse &storehouse, int s, int p, unsigned char dd[2]) {
    storehouse.handyRack.shelf[s].place[p].label[0] = dd[0];
    storehouse.handyRack.shelf[s].place[p].label[1] = dd[1];
}

void setLS (Storehouse &storehouse, int p, unsigned char dd[2]) {
    storehouse.handyShelf.place[p].label[0] = dd[0];
    storehouse.handyShelf.place[p].label[1] = dd[1];
}

void getLW (Storehouse &storehouse, int w, int r, int s, int p) {
    cout << storehouse.warehouse[w].rack[r].shelf[s].place[p].label[0] << storehouse.warehouse[w].rack[r].shelf[s].place[p].label[1] << "\n";
}

void getLH (Storehouse &storehouse, int w, int p) {
    cout << storehouse.warehouse[w].hadnyShelf.place[p].label[0] << storehouse.warehouse[w].hadnyShelf.place[p].label[1] << "\n";
}

void getLR (Storehouse &storehouse, int s, int p) {
    cout << storehouse.handyRack.shelf[s].place[p].label[0] << storehouse.handyRack.shelf[s].place[p].label[1] << "\n";
}

void getLS (Storehouse &storehouse, int p) {
    cout << storehouse.handyShelf.place[p].label[0] << storehouse.handyShelf.place[p].label[1] << "\n";
}

void movW (Storehouse &storehouse, int wb, int rb, int sb, int we, int re, int se, int p, int a) {
    if ((storehouse.warehouse[we].rack[re].shelf[se].place[p].ware + a) > 65535)
        a = 65535 - storehouse.warehouse[we].rack[re].shelf[se].place[p].ware;
    if ((storehouse.warehouse[wb].rack[rb].shelf[sb].place[p].ware - a) < 0)
        a = storehouse.warehouse[wb].rack[rb].shelf[sb].place[p].ware;
    storehouse.warehouse[we].rack[re].shelf[se].place[p].ware += a;
    storehouse.warehouse[wb].rack[rb].shelf[sb].place[p].ware -= a;
}

void movH (Storehouse &storehouse, int w, int r, int s, int p, int a) {
    if ((storehouse.warehouse[w].hadnyShelf.place[p].ware + a) > 65535)
        a = 65535 - storehouse.warehouse[w].hadnyShelf.place[p].ware;
    if ((storehouse.warehouse[w].rack[r].shelf[s].place[p].ware - a) < 0)
        a = storehouse.warehouse[w].rack[r].shelf[s].place[p].ware;
    storehouse.warehouse[w].hadnyShelf.place[p].ware += a;
    storehouse.warehouse[w].rack[r].shelf[s].place[p].ware -= a;
}

void movR (Storehouse &storehouse, int w, int r, int sb, int se, int p, int a) {
    if ((storehouse.handyRack.shelf[se].place[p].ware + a) > 65535)
        a = 65535 - storehouse.handyRack.shelf[se].place[p].ware;
    if ((storehouse.warehouse[w].rack[p].shelf[sb].place[p].ware - a) < 0)
        a = storehouse.warehouse[w].rack[p].shelf[sb].place[p].ware;
    storehouse.handyRack.shelf[se].place[p].ware += a;
    storehouse.warehouse[w].rack[p].shelf[sb].place[p].ware -= a;
}

void movS (Storehouse &storehouse, int s, int p, int a) {
    if ((storehouse.handyShelf.place[p].ware + a) > 65535)
        a = 65535 - storehouse.handyShelf.place[p].ware;
    if ((storehouse.handyRack.shelf[s].place[p].ware - a) < 0)
        a = storehouse.handyRack.shelf[s].place[p].ware;
    storehouse.handyRack.shelf[s].place[p].ware -= a;
    storehouse.handyShelf.place[p].ware += a;
}

int main() {
    //setZeroAmount(storehouse);
    
    char order[7];
    do {
        cin >> order;
        
        // SET
        if (charEquality(order, (char*)"SET-AP")) {
            int wb, rb, sb, pe;
            cin >> wb >> rb >> sb >> pe;
            if (pe > 128 || wb >= storehouse.warehousesAmount || rb >= storehouse.warehouse[wb].racksAmount || sb >= storehouse.warehouse[wb].rack[rb].shelvesAmount) cout << "error\n";
            else setAP(storehouse, wb, rb, sb, pe);
        }
        else if (charEquality(order, (char*)"SET-AS")) {
            int wb, rb, se, pe;
            cin >> wb >> rb >> se >> pe;
            if (se > 128 || pe > 128 ||wb >= storehouse.warehousesAmount || rb >= storehouse.warehouse[wb].racksAmount) cout << "error\n";
            else setAS(storehouse, wb, rb, se, pe);
        }
        else if (charEquality(order, (char*)"SET-AR")) {
            int wb, re, se, pe;
            cin >> wb >> re >> se >> pe;
            if (re > 128 || se > 128 || pe > 128 || wb >= storehouse.warehousesAmount) cout << "error\n";
            else setAR(storehouse, wb, re, se, pe);
            }
        else if (charEquality(order, (char*)"SET-AW")) {
            int we, re, se, pe;
            cin >> we >> re >> se >> pe;
            if (we > 128 || re > 128 || se > 128 || pe > 128) cout << "error\n";
            else setAW(storehouse, we, re, se, pe);
        }
        else if (charEquality(order, (char*)"SET-HW")) {
            int w, p; cin >> w >> p;
            if (p > 128 || w >= storehouse.warehousesAmount) cout << "error\n";
            else setHW(storehouse, w, p);
        }
        else if (charEquality(order, (char*)"SET-HR")) {
            int s, p; cin >> s >> p;
            if (p > 128 || s > 128) cout << "error\n";
            else setHR(storehouse, s, p);
        }
        else if (charEquality(order, (char*)"SET-HS")) {
            int p; cin >> p;
            if (p > 128) cout << "error\n";
            else setHS(storehouse, p);
        }
        
        //SET-L
        else if (charEquality(order, (char*)"SET-LW")) {
            int w, r, s, p; cin >> w >> r >> s >> p;
            unsigned char dd[2]; cin >> dd[0] >> dd[1];
            if (w >= storehouse.warehousesAmount || r >= storehouse.warehouse[w].racksAmount || s >= storehouse.warehouse[w].rack[r].shelvesAmount || p >= storehouse.warehouse[w].rack[r].shelf[s].placesAmount) cout << "error\n";
            else setLW(storehouse, w, r, s, p, dd);
        }
        else if (charEquality(order, (char*)"SET-LH")) {
            int w, p; cin >> w >> p;
            unsigned char dd[2]; cin >> dd[0] >> dd[1];
            if (w >= storehouse.warehousesAmount || p >= storehouse.warehouse[w].hadnyShelf.placesAmount) cout << "error\n";
            else setLH(storehouse, w, p, dd);
        }
        else if (charEquality(order, (char*)"SET-LR")) {
            int s, p; cin >> s >> p;
            unsigned char dd[2]; cin >> dd[0] >> dd[1];
            if (s >= storehouse.handyRack.shelvesAmount || p >= storehouse.handyRack.shelf[s].placesAmount) cout << "error\n";
            else setLR(storehouse, s, p, dd);
        }
        else if (charEquality(order, (char*)"SET-LS")) {
            int p; cin >> p;
            unsigned char dd[2]; cin >> dd[0] >> dd[1];
            if (p >= storehouse.handyShelf.placesAmount) cout << "error\n";
            else setLS(storehouse, p, dd);
        }
        
        // FILL
        else if (charEquality(order, (char*)"FILL")) {
            int w, r, s, p, a;
            cin >> w >> r >> s >> p >> a;
            if (w > 128 || r > 128 || s > 128 || p > 128 || a > 65535) cout << "error\n";
            else fill(storehouse, w, r, s, p, a);
        }
        
        // GET
        else if (charEquality(order, (char*)"GET-E")) {
            cout << getE(storehouse) << "\n";
        }
        else if (charEquality(order, (char*)"GET-W")) {
            int w; cin >> w;
            if (w >= storehouse.warehousesAmount) cout << "error\n";
            else cout << getW(storehouse, w) << "\n";
        }
        else if (charEquality(order, (char*)"GET-RW")) {
            int w, r; cin >> w >> r;
            
            bool error = 0;
            if (w >= storehouse.warehousesAmount) error = 1;
            if (r >= storehouse.warehouse[w].racksAmount) error = 1;
            
            if (error) cout << "error\n";
            else cout << getRW(storehouse, w, r) << "\n";
        }
        else if (charEquality(order, (char*)"GET-RH")) {
            cout << getRH(storehouse) << "\n";
        }
        else if (charEquality(order, (char*)"GET-SW")) {
            int w, r, s; cin >> w >> r >> s;
            
            bool error = 0;
            if (w >= storehouse.warehousesAmount) error = 1;
            
            if (r >= storehouse.warehouse[w].racksAmount) error = 1;
            
            if (s >= storehouse.warehouse[w].rack[r].shelvesAmount) error = 1;
            
            if (error) cout << "error\n";
            else cout << getSW(storehouse, w, r, s) << "\n";
        }
        else if (charEquality(order, (char*)"GET-SH")) {
            int w; cin >> w;
            
            if (w >= storehouse.warehousesAmount) cout << "error\n";
            else cout << getSH(storehouse, w) << "\n";
        }
        else if (charEquality(order, (char*)"GET-SR")) {
            int s; cin >> s;
            
            if (s >= storehouse.handyRack.shelvesAmount) cout << "error\n";
            else cout << getSR(storehouse, s) << "\n";
        }
        else if (charEquality(order, (char*)"GET-S")) {
            cout << getS(storehouse) << "\n";
        }
        
        
        // GET-L
        else if (charEquality(order, (char*)"GET-LW")) {
            int w, r, s, p; cin >> w >> r >> s >> p;
            if (w >= storehouse.warehousesAmount || r >= storehouse.warehouse[w].racksAmount || s >= storehouse.warehouse[w].rack[r].shelvesAmount || p >= storehouse.warehouse[w].rack[r].shelf[s].placesAmount) cout << "error\n";
            else getLW(storehouse, w, r, s, p);
        }
        else if (charEquality(order, (char*)"GET-LH")) {
            int w, p; cin >> w >> p;
            if (w >= storehouse.warehousesAmount || p >= storehouse.warehouse[w].hadnyShelf.placesAmount) cout << "error\n";
            else getLH(storehouse, w, p);
        }
        else if (charEquality(order, (char*)"GET-LR")) {
            int s, p; cin >> s >> p;
            if (s >= storehouse.handyRack.shelvesAmount || p >= storehouse.handyRack.shelf[s].placesAmount) cout << "error\n";
            else getLR(storehouse, s, p);
        }
        else if (charEquality(order, (char*)"GET-LS")) {
            int p; cin >> p;
            if (p >= storehouse.handyShelf.placesAmount) cout << "error\n";
            else getLS(storehouse, p);
        }
        
        
        // PUT
        else if (charEquality(order, (char*)"PUT-W")) {
            int w, r, s, p, a; cin >> w >> r >> s >> p >> a;
            if (w >= storehouse.warehousesAmount || r >= storehouse.warehouse[w].racksAmount || s >= storehouse.warehouse[w].rack[r].shelvesAmount || p >= storehouse.warehouse[w].rack[r].shelf[s].placesAmount) cout << "error\n";
            else putW(storehouse, w, r, s, p, a);
        }
        else if (charEquality(order, (char*)"PUT-H")) {
            int w, p, a; cin >> w >> p >> a;
            if (w >= storehouse.warehousesAmount || p >= storehouse.warehouse[w].hadnyShelf.placesAmount) cout << "error\n";
            else putH(storehouse, w, p, a);
        }
        else if (charEquality(order, (char*)"PUT-R")) {
            int s, p, a; cin >> s >> p >> a;
            if (s >= storehouse.handyRack.shelvesAmount || p >= storehouse.handyRack.shelf[s].placesAmount) cout << "error\n";
            else putR(storehouse, s, p, a);
        }
        else if (charEquality(order, (char*)"PUT-S")) {
            int p, a; cin >> p >> a;
            if (p >= storehouse.handyShelf.placesAmount) cout << "error\n";
            else putS(storehouse, p, a);
        }
        
        // POP
        else if (charEquality(order, (char*)"POP-W")) {
            int w, r, s, p, a; cin >> w >> r >> s >> p >> a;
            if (w >= storehouse.warehousesAmount || r >= storehouse.warehouse[w].racksAmount || s >= storehouse.warehouse[w].rack[r].shelvesAmount || p >= storehouse.warehouse[w].rack[r].shelf[s].placesAmount) cout << "error\n";
            else popW(storehouse, w, r, s, p, a);
        }
        else if (charEquality(order, (char*)"POP-H")) {
            int w, p, a; cin >> w >> p >> a;
            if (w >= storehouse.warehousesAmount || p >= storehouse.warehouse[w].hadnyShelf.placesAmount) cout << "error\n";
            else popH(storehouse, w, p, a);
        }
        else if (charEquality(order, (char*)"POP-R")) {
            int s, p, a; cin >> s >> p >> a;
            if (s >= storehouse.handyRack.shelvesAmount || p >= storehouse.handyRack.shelf[s].placesAmount) cout << "error\n";
            else popR(storehouse, s, p, a);
        }
        else if (charEquality(order, (char*)"POP-S")) {
            int p, a; cin >> p >> a;
            if (p >= storehouse.handyShelf.placesAmount) cout << "error\n";
            else popS(storehouse, p, a);
        }
        
        // MOV
        else if (charEquality(order, (char*)"MOV-W")) {
            int wb, rb, sb, we, re, se, p, a;
            cin >> wb >> rb >> sb >> we >> re >> se >> p >> a;
            if (wb >= storehouse.warehousesAmount) cout << "error\n";
            else if (rb >= storehouse.warehouse[wb].racksAmount) cout << "error\n";
            else if (sb >= storehouse.warehouse[wb].rack[rb].shelvesAmount) cout << "error\n";
            else if (p >= storehouse.warehouse[wb].rack[rb].shelf[sb].placesAmount) cout << "error\n";
            else if (we >= storehouse.warehousesAmount) cout << "error\n";
            else if (re >= storehouse.warehouse[we].racksAmount) cout << "error\n";
            else if (se >= storehouse.warehouse[we].rack[re].shelvesAmount) cout << "error\n";
            else if (p >= storehouse.warehouse[we].rack[re].shelf[se].placesAmount) cout << "error\n";
            else movW(storehouse, wb, rb, sb, we, re, se, p, a);
            
        }
        else if (charEquality(order, (char*)"MOV-H")) {
            int w, r, s, p, a;
            cin >> w >> r >> s >> p >> a;
            if (w >= storehouse.warehousesAmount) cout << "error\n";
            else if (r >= storehouse.warehouse[w].racksAmount) cout << "error\n";
            else if (s >= storehouse.warehouse[w].rack[r].shelvesAmount) cout << "error\n";
            else if (p >= storehouse.warehouse[w].rack[r].shelf[s].placesAmount) cout << "error\n";
            
            else if (p >= storehouse.warehouse[w].hadnyShelf.placesAmount) cout << "error\n";
            else movH(storehouse, w, r, s, p, a);
        }
        else if (charEquality(order, (char*)"MOV-R")) {
            int w, r, sb, se, p, a;
            cin >> w >> r >> sb >> se >> p >> a;
            if (w >= storehouse.warehousesAmount) cout << "error\n";
            else if (se >= storehouse.handyRack.shelvesAmount) cout << "error\n";
            else if (p >= storehouse.handyRack.shelf[se].placesAmount) cout << "error\n";
            
            else if (r >= storehouse.warehouse[w].racksAmount) cout << "error\n";
            else if (sb >= storehouse.warehouse[w].rack[r].shelvesAmount) cout << "error\n";
            else if (p >= storehouse.warehouse[w].rack[r].shelf[sb].placesAmount) cout << "error\n";
            else movR(storehouse, w, r, sb, se, p, a);
        }
        else if (charEquality(order, (char*)"MOV-S")) {
            int s, p, a;
            cin >> s >> p >> a;
            if (s >= storehouse.handyRack.shelvesAmount) cout << "error\n";
            else if (p >= storehouse.handyRack.shelf[s].placesAmount) cout << "error\n";
            else if (p >= storehouse.handyShelf.placesAmount) cout << "error\n";
            else movS(storehouse, s, p, a);
        }
        
    } while (!charEquality(order, (char*)"END"));
    
    //std::cout << "Hello, World!\n";
    return 0;
}
