/* crusher.c */

int range;
int bearing;
int dmg; 

main()
    {
    dmg = 0;
    range = 0;
    bearing = 0;
    while (1)
        {
        if (range == 0)
            check_corners();
        else if (range > 700)
            pursue();
        else
            fire();

        if (dmg != damage())
            {
            int new_x, new_y;
            new_x = rand(980) + 10;
            new_y = rand(980) + 10;
            while (loc_x() != new_x && loc_y() != new_y)
                drive(plot_course(new_x, new_y), 100);
            drive(0,0);
            dmg = damage();
            }
        }
    }

fire()
    {
    while (range)
        {
        cannon(bearing, range);
        range = scan(bearing, 1);
        if (dmg != damage())
            range = 0;
        }
    }

pursue()
    {
    while (range > 700)
        {
        drive(bearing, 100);
        range = scan(bearing, 1);
        }
    drive(bearing, 0);
    if (range)
       fire();
    }

check_corners()
    {
    int b1, b2, b3, b4;
    b1 = plot_course(0,0);
    b2 = plot_course(0,999);
    b3 = plot_course(999,999);
    b4 = plot_course(999,0);
    bearing = -1;
    while (bearing == -1)
        {
        if (range = scan(b1 - 10, 10))
            bearing = b1 - 10;
        else if (range = scan(b1 + 10, 10))
            bearing = b1 + 10;
        else if (range = scan(b2 - 10, 10))
            bearing = b2 - 10;
        else if (range = scan(b2 + 10, 10))
            bearing = b2 + 10;
        else if (range = scan(b3 - 10, 10))
            bearing = b3 - 10;
        else if (range = scan(b3 + 10, 10))
            bearing = b3 + 10;
        else if (range = scan(b4 - 10, 10))
            bearing = b4 - 10;
        else if (range = scan(b4 + 10, 10))
            bearing = b4 + 10;
        if (dmg != damage())
            return;
        }
    zero_in();
    }

zero_in()
    {
    if (range = scan(bearing - 5, 5))
        bearing -= 5;
    else
        bearing += 5;
    if (range = scan(bearing - 3, 3))
        bearing -= 3;
    else
        bearing += 3;
    if (range = scan(bearing - 2, 2))
        bearing -= 2;
    else
        bearing += 2;
    if (range = scan(bearing - 1, 1))
        bearing -= 1;
    else
        bearing += 1;
    }
    
/* plot course function, return degree heading to */
/* reach destination x, y; uses atan() trig function */
plot_course(xx,yy)
    int xx, yy;
    {
    int d;
    int x,y;
    int scale;
    int curx, cury;

    scale = 100000;  /* scale for trig functions */
    curx = loc_x();  /* get current location */
    cury = loc_y();
    x = curx - xx;
    y = cury - yy;

    /* atan only returns -90 to +90, so figure out how to use */
    /* the atan() value */

    if (x == 0) {      /* x is zero, we either move due north or south */
        if (yy > cury)
            d = 90;        /* north */
        else
            d = 270;       /* south */
    } else {
        if (yy < cury) {
            if (xx > curx)
                d = 360 + atan((scale * y) / x);  /* south-east, quadrant 4 */
            else
                d = 180 + atan((scale * y) / x);  /* south-west, quadrant 3 */ 
        } else {
            if (xx > curx)
                d = atan((scale * y) / x);        /* north-east, quadrant 1 */
            else
                d = 180 + atan((scale * y) / x);  /* north-west, quadrant 2 */
        }
    }
    return (d);
    }

distance(x1,y1,x2,y2)
    int x1;
    int y1;
    int x2;
    int y2;
    {
    int x, y;

    int d;
    x = x1 - x2;
    y = y1 - y2;
    d = sqrt((x*x) + (y*y));

    return(d);
    }

