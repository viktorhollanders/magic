# Magic

## Author

Viktor Hollanders <viktorhollanders@hey.com>

## About

This is a simple JRPG game. It is a two-player game that lets each player create his/her mage and then battle each other.
A player can select three starting spells and as they level up they can update their mana, level up and get better health.
At levels 5, 12, and 25 new spells become available. In this game it is critical to win as this allows the player to get updates.

The spells are split into three categories: Attack spells, defense spells, and healing spells. Each time a player casts a spell, the spell power is calculated from a random range which is 0-5 for starter and beginner spells, 6-12 for intermediate spells, and 13-20 for advanced spells.

So go and select your arcane name and take your place among the legendary Mages of the Dueling Grounds, where cosmic powers clash and only the most cunning will ascend to immortal glory!


## Building

To build the game run:

```sh
  make
```

To play the game:

```sh
  make startGame
```

To clean the project run:

```sh
  make clean
```

## Extensions

This sections describes what got added on top of the base game.

- There is aleveling system for the characters.
- More stats where added like mana, defense and level,
- The random header was used to create the randomness for the spells power.
- Multiple entities, each player can chose from more than one spell and the more spells that the player has added the more he/she has to chose from.
- the UI was slightly enhanced by clearing the terminal after certain acctions.

I hope you have as much fun playing this as I had creating this game.
