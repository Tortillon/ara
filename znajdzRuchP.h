ruch znajdzRuchP(Pole *wsk_to_board){

    ruch Ruch;
    Pole board[17*34+34];

    for(int i = 0; i < 17; i ++)
    {
        for(int j = 0; j < 34; j ++)
        {
            if((i%2==0&&j%2==0)||i%2==1&&j%2==1)
            board[i*34+j] = wsk_to_board[i * 34 + j];
        }
    }

    bool r=0;

    int actualWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
    int bestWartosc=actualWartosc;
    int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
    for(int x = 0; x < 17; x++){

        for (int y = 0; y< 34; y++){

            if((x%2==y%2)&&front_fields[x*34+y].name!="notexist"){

                if(front_fields[x*34+y].owner==2){

                    if (front_fields[x* 34 + y].name == "pawn"){
                                for (int l = y-4; l<= y+4; l++){
                                    if(l>=0&&l<34){
                                        if((x%2==l%2)&&front_fields[x*34+l].name!="notexist"){

                                                if(canAttack(front_fields, x, y, x, l)||(canMove(front_fields, x, y, x, l)))
                                                    action(front_fields, x, y, x, l);
                                                    int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
                                                    if(newWartosc<bestWartosc){
                                                        bestWartosc=newWartosc;
                                                        Ruch.x=x;
                                                        Ruch.y=y;
                                                        Ruch.tx=x;
                                                        Ruch.ty=l;
                                                        r=1;

                                                    }
                                                    wroc(board);

                                        }
                                    }
                                }
                                int a;
                                tura==1?a=1:a=-1;
                                if(x>0){
                                    if(canAttack(front_fields, x, y, x-1, y+a)||canMove(front_fields, x, y, x-1, y+a)){
                                        action(front_fields, x, y, x-1, y+a);
                                        int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
                                        if(newWartosc<bestWartosc){
                                            bestWartosc=newWartosc;
                                            Ruch.x=x;
                                            Ruch.y=y;
                                            Ruch.tx=x-1;
                                            Ruch.ty=y+a;
                                            r=1;

                                        }
                                        wroc(board);
                                    }

                                }
                                if(x<16){
                                    if(canAttack(front_fields, x, y, x+1, y+a)||canMove(front_fields, x, y, x+1, y+a)){
                                        action(front_fields, x, y, x+1, y+a);
                                        int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
                                        if(newWartosc<bestWartosc){
                                            bestWartosc=newWartosc;
                                            Ruch.x=x;
                                            Ruch.y=y;
                                            Ruch.tx=x+1;
                                            Ruch.ty=y+a;
                                            r=1;

                                        }
                                        wroc(board);
                                    }
                                }
                    } else if(front_fields[x* 34 + y].name == "ghost"){
                        for(int k = x-2; k <= x+2; k++){
                            for (int l = y - 4; l<= y+4; l++){
                                if(k>-1&&k<17&&l>=0&&l<34){
                                    if(canAttack(front_fields, x, y, k, l)||canMove(front_fields, x, y, k, l)){
                                        action(front_fields, x, y, k, l);
                                        int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
                                        if(newWartosc<bestWartosc){
                                            bestWartosc=newWartosc;
                                            Ruch.x=x;
                                            Ruch.y=y;
                                            Ruch.tx=k;
                                            Ruch.ty=l;
                                            r=1;

                                        }
                                        wroc(board);
                                    }
                                }

                            }
                        }
                    }

                    //krolik
                    else if(front_fields[x* 34 + y].name == "king"){
                        for(int k = x-1; k <= x+1; k++){
                            for (int l = y-2; l <= y+2; l++){
                                if(k>-1&&k<17&&l>=0&&l<34){
                                    if(canAttack(front_fields, x, y, k, l)||canMove(front_fields, x, y, k, l)){
                                        action(front_fields, x, y, k, l);
                                        int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
                                        if(newWartosc<bestWartosc){
                                            bestWartosc=newWartosc;
                                            Ruch.x=x;
                                            Ruch.y=y;
                                            Ruch.tx=k;
                                            Ruch.ty=l;
                                            r=1;

                                        }
                                        wroc(board);
                                    }
                                }
                            }
                        }
                    }

                    //wieza
                    else if(front_fields[x* 34 + y].name == "tower"){
                        for(int k = x-2; k <= x+2; k++){
                            for (int l = y-4; l <= y+4; l++){
                                if(k>-1&&k<17&&l>=0&&l<34){
                                    if(canMove(front_fields, x, y, k, l)){
                                        action(front_fields, x, y, k, l);
                                        int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
                                        if(newWartosc<bestWartosc){
                                            bestWartosc=newWartosc;
                                            Ruch.x=x;
                                            Ruch.y=y;
                                            Ruch.tx=k;
                                            Ruch.ty=l;
                                            r=1;

                                        }
                                        wroc(board);
                                    }
                                }
                            }
                        int nx=x+2;
                        int ny=y+2;
                        while(nx<17&&ny<34&&nx<x+4){
                            nx++;
                            ny++;
                            if(canAttack(front_fields, x, y, nx, ny)){
                                action(front_fields, x, y, nx, ny);
                                int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
                                if(newWartosc<bestWartosc){
                                    bestWartosc=newWartosc;
                                    Ruch.x=x;
                                    Ruch.y=y;
                                    Ruch.tx=nx;
                                    Ruch.ty=ny;
                                    r=1;

                                }
                                wroc(board);
                            }
                        }
                        nx=x-2;
                        ny=y-2;
                        while(nx>0&&ny>0&&nx>x-4){
                            nx--;
                            ny--;
                            if(canAttack(front_fields, x, y, nx, ny)){
                                action(front_fields, x, y, nx, ny);

                                int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
                                if(newWartosc<bestWartosc){
                                    bestWartosc=newWartosc;
                                    Ruch.x=x;
                                    Ruch.y=y;
                                    Ruch.tx=nx;
                                    Ruch.ty=ny;
                                    r=1;

                                }
                                wroc(board);

                            }
                        }
                        nx=x+2;
                        ny=y-2;
                        while(nx<17&&ny>0&&nx<x+4){
                            nx++;
                            ny--;
                            if(canAttack(front_fields, x, y, nx, ny)){
                                action(front_fields, x, y, nx, ny);
                                int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
                                if(newWartosc<bestWartosc){
                                    bestWartosc=newWartosc;
                                    Ruch.x=x;
                                    Ruch.y=y;
                                    Ruch.tx=nx;
                                    Ruch.ty=ny;
                                    r=1;

                                }
                                wroc(board);
                            }
                        }
                        nx=x-2;
                        ny=y+2;
                        while(nx>0&&ny<34&&nx>x-4){
                            nx--;
                            ny++;
                            if(canAttack(front_fields, x, y, nx, ny)){
                                action(front_fields, x, y, nx, ny);
                                int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
                                if(newWartosc<bestWartosc){
                                    bestWartosc=newWartosc;
                                    Ruch.x=x;
                                    Ruch.y=y;
                                    Ruch.tx=nx;
                                    Ruch.ty=ny;
                                    r=1;

                                }
                                wroc(board);
                            }
                        }
                        for(int i=y+6; i<=y+8; i+=2){
                            if(canAttack(front_fields, x, y, x, i)){
                                action(front_fields, x, y, x, i);
                                int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
                                if(newWartosc<bestWartosc){
                                    bestWartosc=newWartosc;
                                    Ruch.x=x;
                                    Ruch.y=y;
                                    Ruch.tx=x;
                                    Ruch.ty=i;
                                    r=1;

                                }
                                wroc(board);
                            }
                        }
                        for(int i=y-8; i<=y-6; i+=2){
                            if(canAttack(front_fields, x, y, x, i)){
                                action(front_fields, x, y, x, i);
                                int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
                                if(newWartosc<bestWartosc){
                                    bestWartosc=newWartosc;
                                    Ruch.x=x;
                                    Ruch.y=y;
                                    Ruch.tx=x;
                                    Ruch.ty=i;
                                    r=1;

                                }
                                wroc(board);
                            }
                        }
                        }
                    }

                    //szarza
                    else if(front_fields[x* 34 + y].name == "charge"){
                            for (int l = 0; l <= 33; l++){
                                if(l>=0&&l<34){
                                    if(canAttack(front_fields, x, y, x, l)||canMove(front_fields, x, y, x, l)){
                                        action(front_fields, x, y, x, l);
                                        int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
                                        if(newWartosc<bestWartosc){
                                            bestWartosc=newWartosc;
                                            Ruch.x=x;
                                            Ruch.y=y;
                                            Ruch.tx=x;
                                            Ruch.ty=l;
                                            r=1;

                                        }
                                        wroc(board);
                                    }
                                }
                            }
                            if(x-2>0){
                                if(canMove(front_fields, x, y, x-2, y)){
                                    action(front_fields, x, y, x-2, y);
                                    int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
                                    if(newWartosc<bestWartosc){
                                        bestWartosc=newWartosc;
                                        Ruch.x=x;
                                        Ruch.y=y;
                                        Ruch.tx=x-2;
                                        Ruch.ty=y;
                                        r=1;

                                    }
                                    wroc(board);
                                }
                            }
                            if(x+2>0){
                                if(canMove(front_fields, x, y, x+2, y)){
                                    action(front_fields, x, y, x+2, y);
                                    int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
                                    if(newWartosc<bestWartosc){
                                        bestWartosc=newWartosc;
                                        Ruch.x=x;
                                        Ruch.y=y;
                                        Ruch.tx=x+2;
                                        Ruch.ty=y;
                                        r=1;

                                    }
                                    wroc(board);
                                }
                            }
                    }else if(front_fields[x* 34 + y].name == "cav"){
                        int nx=x+1;
                        int ny=y+1;
                        while(nx<=16&&ny<=33){
                            if(canMove(front_fields, x, y, nx, ny)){
                                action(front_fields, x, y, nx, ny);
                                int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
                                if(newWartosc<bestWartosc){
                                    bestWartosc=newWartosc;
                                    Ruch.x=x;
                                    Ruch.y=y;
                                    Ruch.tx=nx;
                                    Ruch.ty=ny;
                                    r=1;

                                }
                                wroc(board);
                            }
                            nx++;
                            ny++;
                        }
                        nx=x-1;
                        ny=y-1;
                        while(nx>=0&&ny>=0){
                            if(canMove(front_fields, x, y, nx, ny)){
                                action(front_fields, x, y, nx, ny);
                                int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
                                if(newWartosc<bestWartosc){
                                    bestWartosc=newWartosc;
                                    Ruch.x=x;
                                    Ruch.y=y;
                                    Ruch.tx=nx;
                                    Ruch.ty=ny;
                                    r=1;

                                }
                                wroc(board);
                            }
                            nx--;
                            ny--;
                        }
                        nx=x+1;
                        ny=y-1;
                        while(nx<=16&&ny>=0){
                            if(canMove(front_fields, x, y, nx, ny)){
                                action(front_fields, x, y, nx, ny);
                                int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
                                if(newWartosc<bestWartosc){
                                    bestWartosc=newWartosc;
                                    Ruch.x=x;
                                    Ruch.y=y;
                                    Ruch.tx=nx;
                                    Ruch.ty=ny;
                                    r=1;

                                }
                                wroc(board);
                            }
                            nx++;
                            ny--;
                        }
                        nx=x-1;
                        ny=y+1;
                        while(nx>=0&&ny<=33){
                            if(canMove(front_fields, x, y, nx, ny)){
                                action(front_fields, x, y, nx, ny);
                                int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
                                if(newWartosc<bestWartosc){
                                    bestWartosc=newWartosc;
                                    Ruch.x=x;
                                    Ruch.y=y;
                                    Ruch.tx=nx;
                                    Ruch.ty=ny;
                                    r=1;

                                }
                                wroc(board);
                            }
                            nx--;
                            ny++;
                        }

                    }else if(front_fields[x* 34 + y].name == "mystery"){
                        int nx=x+1;
                        int ny=y+1;
                        while(nx<17&&ny<34){

                            if(canAttack(front_fields, x, y, nx, ny)||canMove(front_fields, x, y, nx, ny)){
                                action(front_fields, x, y, nx, ny);
                                int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
                                if(newWartosc<bestWartosc){
                                    bestWartosc=newWartosc;
                                    Ruch.x=x;
                                    Ruch.y=y;
                                    Ruch.tx=nx;
                                    Ruch.ty=ny;
                                    r=1;

                                }
                                wroc(board);
                            }
                            nx++;
                            ny++;
                        }
                        nx=x-1;
                        ny=y-1;
                        while(nx>0&&ny>0){
                            if(canAttack(front_fields, x, y, nx, ny)||canMove(front_fields, x, y, nx, ny)){
                                action(front_fields, x, y, nx, ny);
                                int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
                                if(newWartosc<bestWartosc){
                                    bestWartosc=newWartosc;
                                    Ruch.x=x;
                                    Ruch.y=y;
                                    Ruch.tx=nx;
                                    Ruch.ty=ny;
                                    r=1;

                                }
                                wroc(board);
                            }
                            nx--;
                            ny--;
                        }
                        nx=x+1;
                        ny=y-1;
                        while(nx<17&&ny>0){
                            if(canAttack(front_fields, x, y, nx, ny)||canMove(front_fields, x, y, nx, ny)){
                                action(front_fields, x, y, nx, ny);
                                int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
                                if(newWartosc<bestWartosc){
                                    bestWartosc=newWartosc;
                                    Ruch.x=x;
                                    Ruch.y=y;
                                    Ruch.tx=nx;
                                    Ruch.ty=ny;
                                    r=1;

                                }
                                wroc(board);
                            }
                            nx++;
                            ny--;
                        }
                        nx=x-1;
                        ny=y+1;
                        while(nx>0&&ny<34){
                            if(canAttack(front_fields, x, y, nx, ny)||canMove(front_fields, x, y, nx, ny)){
                                action(front_fields, x, y, nx, ny);
                                int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
                                if(newWartosc<bestWartosc){
                                    bestWartosc=newWartosc;
                                    Ruch.x=x;
                                    Ruch.y=y;
                                    Ruch.tx=nx;
                                    Ruch.ty=ny;
                                    r=1;

                                }
                                wroc(board);
                            }
                            nx--;
                            ny++;
                        }
                        for(int i=0; i<34; i++){
                            if(canAttack(front_fields, x, y, x, i)||canMove(front_fields, x, y, x, i)){
                                action(front_fields, x, y, x, i);
                                int newWartosc=zliczWartosciAI(front_fields)-zliczWartosciP(front_fields);
                                if(newWartosc<bestWartosc){
                                    bestWartosc=newWartosc;
                                    Ruch.x=x;
                                    Ruch.y=y;
                                    Ruch.tx=x;
                                    Ruch.ty=i;
                                    r=1;

                                }
                                wroc(board);
                            }
                        }




                    }
                }
            }
        }
    }
    if(!r){
        Ruch.x=0;
        Ruch.y=0;
        Ruch.tx=0;
        Ruch.ty=0;
    }
    return Ruch;
}
