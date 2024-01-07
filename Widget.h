//
// Created by 26798 on 2024/1/6.
//

#ifndef MAIN_CPP_WIDGET_H
#define MAIN_CPP_WIDGET_H

#include "HEAD.h"

class Widget {
private:
    int width;
    int height;
    int currentIndex;
    std :: vector<IMAGE*> pages;
    std :: vector<std :: vector<Button*>> buttons;
    void addPage(IMAGE * page)
    {
        pages.push_back(page);
        buttons.push_back({});
    }

    void addButton(int index, Button * button)
    {
        if(index >= 0 && index < buttons.size())
            buttons[index].push_back(button);
    }

    void setCurrentIndex(int index)
    {
        if(index >= 0 && index < pages.size())
            currentIndex = index;
    }

    void MOUSECLICK(int mousex, int mousey)
    {
        if(currentIndex >= 0 && currentIndex < buttons.size())
        {
            for(Button * button: buttons[currentIndex])
                if(button->checkClick(mousex, mousey))
                    break;
        }
    }

    void MOUSEMOVE(int mousex, int mousey)
    {
        if(currentIndex >= 0 && currentIndex < buttons.size())
        {
            for(Button * button : buttons[currentIndex])
                button->checkMouseOver(mousex, mousey);
        }
    }

    void draw()
    {
        if(currentIndex >= 0 && currentIndex < pages.size())
        {
            putimage(0, 0, pages[currentIndex]);

            if(currentIndex >= 0 && currentIndex < buttons.size())
                for(auto button : buttons[currentIndex])
                    button->draw();
        }
    }
public:
    Widget(int width, int height): width(width), height(height), currentIndex(-1){}

    ~Widget(){}

    void init()
    {
        initgraph(width, height);
//        IMAGE* page1 = new IMAGE(width, height);
//        setfillcolor(RGB(240, 240, 240));
//        solidrectangle(0, 0, width, height);
//        getimage(page1, 0, 0, width, height);
        IMAGE* page1 = new IMAGE;
        loadimage(page1, _T("C:\\Users\\26798\\Desktop\\11111\\source\\ui.png"), 1200, 800, 1);
        addPage(page1);

        char s1_1[50] = {"Map"};
        char s1_2[50] = {"Help"};
        char s1_3[50] = {"Exit"};
        Button * button1_1 = new Button(480, 370, 210, 60, s1_1, [&]()
        {
//            cleardevice();
            setCurrentIndex(1);
//            setbkcolor(RGB(240, 240, 240));
        });
        addButton(0, button1_1);

        Button * button1_2 = new Button(480, 510, 210, 60, s1_2, [&]()
        {
            setCurrentIndex(4);
        });
        addButton(0, button1_2);

        Button * button1_3 = new Button(480, 650, 210, 60, s1_3, [&]()
        {
            closegraph();
            exit(0);
        });
        addButton(0, button1_3);


        //2
        IMAGE* page2 = new IMAGE;
        loadimage(page2, _T("C:\\Users\\26798\\Desktop\\11111\\source\\map.png"), 1200, 800, 1);
        addPage(page2);

        char s2_1[50] = {"Back"};
        Button * back_button1 = new Button(950, 700, 210, 60, s2_1, [&]()
        {
            setCurrentIndex(0);
        });
        addButton(1, back_button1);


        //3
        IMAGE* page3 = new IMAGE;
        loadimage(page3, _T("C:\\Users\\26798\\Desktop\\11111\\source\\high_hp.png"), 1200, 800, 1);
        addPage(page3);

        char s3_1[50] = {"Back"};
        Button * back_button2 = new Button(950, 700, 210, 60, s3_1, [&]()
        {
            setCurrentIndex(4);
        });
        addButton(2, back_button2);

        //4
        IMAGE* page4 = new IMAGE;
        loadimage(page4, _T("C:\\Users\\26798\\Desktop\\11111\\source\\high_money.png"), 1200, 800, 1);
        addPage(page4);

        addButton(3, back_button2);

        //5
        IMAGE* page5 = new IMAGE;
        loadimage(page5, _T("C:\\Users\\26798\\Desktop\\11111\\source\\map.png"), 1200, 800, 1);
        addPage(page5);

        char s5_1[50] = {"High Hp"};
        char s5_2[50] = {"High Money"};
        Button* hh1 = new Button(950, 200, 210, 60, s5_1, [&]()
        {
            setCurrentIndex(2);
        });

        Button* hh2 = new Button(950, 400, 210, 60, s5_2, [&]()
        {
            setCurrentIndex(3);
        });

        addButton(4, back_button1);
        addButton(4, hh1);
        addButton(4, hh2);

        setCurrentIndex(0);
    }

    void run() {
        ExMessage msg;

        BeginBatchDraw();

        while (true) {
            if (peekmessage(&msg)) {
                int mousex = msg.x;
                int mousey = msg.y;

                switch (msg.message) {
                    case WM_LBUTTONDOWN :
                        MOUSECLICK(mousex, mousey);
                        break;
                    case WM_MOUSEMOVE :
                        MOUSEMOVE(mousex, mousey);
                        break;
                }
            }
            draw();
            FlushBatchDraw();
        }
        EndBatchDraw();
    }

    void close()
    {
        closegraph();
    }
};


#endif //MAIN_CPP_WIDGET_H
