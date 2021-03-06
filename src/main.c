#include <darray.h>
#include <game_state.h>
#include <stdio.h>

int main(int argc, char *argv[argc]) {
  (void)argv;
  (void)argc;

  game_state_t *game = newGame();

  // Cas d'un jeu deux joueurs local
  {
    // J1
    game->camp_allocator->put_in_camp(game->camp_allocator, game,
                                      newLocalPlayer());
    // J2
    game->camp_allocator->put_in_camp(game->camp_allocator, game,
                                      newLocalPlayer());
  }

    /* test darray_t
     * ***********************************************************/

#ifdef Debug
  char *str1 = "Hello World!", *str2 = "How are you?",
       *str3 = "This is a wonderful morning!";
  darray_t *char_array_test;
  char_array_test = darrayNew(sizeof(char *));
  darrayPushBack(char_array_test, &str1);
  darrayPushBack(char_array_test, &str2);
  darrayPushBack(char_array_test, &str3);
  printf("String: %s\n", *(char **)darrayGet(char_array_test, 1));
  void *itr;
  size_t i;
  for (itr = char_array_test->begin, i = 0; itr != char_array_test->end;
       itr = (char *)itr + char_array_test->element_size, ++i) {
    printf("String: %s\n", *(char **)darrayGet(char_array_test, i));
  }
  printf("Hi!\n");
  darrayErase(char_array_test, darrayGet(char_array_test, 1));
  for (itr = char_array_test->begin, i = 0; itr != char_array_test->end;
       itr = (char *)itr + char_array_test->element_size, ++i) {
    printf("String: %s\n", *(char **)darrayGet(char_array_test, i));
  }
  darrayDelete(char_array_test);
#endif

  /* do { */
  /*   for (unsigned i = 0; i < darraySize(game->camps); ++i) { */
  /*     camp_t *camp = *(camp_t **)darrayGet(game->camps, i); */
  /*     player_t *players = darrayGet(camp->players, 0); */
  /*     unsigned n = darraySize(camp->players); */
  /*     while (n--) { */
  /*       result_t r; */
  /*       point_t coordinates; */
  /*       do { */
  /*         coordinates = players->get_action(players, game); */
  /*       } while ((r = doAction(game, players, coordinates)) == REDO); */
  /*       ++players; */
  /*     } */
  /*   } */
  /* } while (turnEndUpdate(game)); */
  return 0;
}
