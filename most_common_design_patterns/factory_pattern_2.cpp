/**
 * Examlple of `factory method' design pattern
 * Copyright (C) 2011 Radek Pazdera
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <string>

class Cup
{
    public:
        Cup()
          : color("")
        {}

        std::string color;

        /* This is the factory method. */
        static Cup* getCup(std::string color);
};

class RedCup : public Cup
{
    public:
        RedCup()
        {
            color = "red";
        }
};

class BlueCup : public Cup
{
    public:
        BlueCup()
        {
            color = "blue";
        }
};

Cup* Cup::getCup(std::string color)
{
    if (color == "red")
        return new RedCup();
    else if (color == "blue")
        return new BlueCup();
    else
        return 0;
}


/* A little testing */
int main()
{
    /* Now we decide the type of the cup at
     * runtime by the factory method argument */
    Cup* redCup  = Cup::getCup("red");
    std::cout << redCup->color << std::endl;

    Cup* blueCup = Cup::getCup("blue");
    std::cout << blueCup->color << std::endl;
}
