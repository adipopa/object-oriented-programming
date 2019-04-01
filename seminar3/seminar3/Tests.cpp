#include "Tests.h"
#include <assert.h>
#include "DynamicVector.h"
#include "Repository.h"
#include "PlayList.h"
#include "Controller.h"

void Tests::testSong()
{
	Duration d{ 4, 54 };
	Song s{ "Ed Sheeran", "I see fire", d, "https://www.youtube.com/watch?v=2fngvQS_PmQ" };
	assert(s.getArtist() == "Ed Sheeran");
	assert(s.getTitle() == "I see fire");
	assert(s.getSource() == "https://www.youtube.com/watch?v=2fngvQS_PmQ");
	assert(s.getDuration().getMinutes() == 4);
	assert(s.getDuration().getSeconds() == 54);
}

void Tests::testDynamicVector()
{
	std::vector<int> v1{ 2 };
	v1.push_back(10);
	v1.push_back(20);
	assert(v1.size() == 2);
	assert(v1[1] == 20);
	v1[1] = 25;
	assert(v1[1] == 25);
	v1.push_back(30);
	assert(v1.size() == 3);

	std::vector<int> v2{ v1 };
	assert(v2.size() == 3);

	std::vector<int> v3;
	v3 = v1;
	assert(v3[0] == 10);

	// test iterator
	std::vector<int>::iterator it = v1.begin();
	assert(*it == 10);
	assert(it != v1.end());
	it++;
	assert(*it == 25);
}

void Tests::testRepository()
{
	Repository repo{};
	Song s{ "Ed Sheeran", "I see fire", Duration{ 4, 54 }, "https://www.youtube.com/watch?v=2fngvQS_PmQ" };
	repo.addSong(s);
	Song res = repo.findByArtistAndTitle("Ed Sheeran", "I see fire");
	assert(res.getTitle() == s.getTitle() && res.getArtist() == s.getArtist());
	res = repo.findByArtistAndTitle("Ed Sheeran", "");
	assert(res.getArtist() == "");

	std::vector<Song> songs = repo.getSongs();
	assert(songs.size() == 1);
}

void Tests::testController()
{
	Repository repo{};
	Song s1{ "Ed Sheeran", "I see fire", Duration{ 4, 54 }, "https://www.youtube.com/watch?v=2fngvQS_PmQ" };
	Song s2{ "X Ambassadors", "Renegades", Duration{ 3, 15 }, "https://www.youtube.com/watch?v=6tu4wWSbnIs" };
	Song s3{ "X Ambassadors", "Renegades", Duration{ 3, 15 }, "https://www.youtube.com/watch?v=6tu4wWSbnIs" };
	repo.addSong(s1);
	repo.addSong(s2);
	repo.addSong(s3);
	Controller controller{ repo };

	std::vector<Song> songs = controller.addAllSongsByArtistToPlaylist("X Ambassadors");

	assert(songs.size() == 2);
}

void Tests::testAll()
{
	testSong();
	//testDynamicVector();
	testRepository();
	testController();
}
