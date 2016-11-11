package leaguestats;

import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;

public class LeagueStatisticsTest {
	LeagueStatistics stats;
	@Before
	public void setUp() throws Exception {
		stats = new LeagueStatistics();
		League league = new League("Football League");
		stats.setLeague(league);
		Division div1 = new Division("Premier Division");
		league.addDivision(div1);
		Division div2 = new Division("Second Division");
		league.addDivision(div2);
		
		Team team1 = new Team("FC 1", 9);
		div1.addTeam(team1);
		Team team2 = new Team("2. FK", 8);
		div1.addTeam(team2);
		Team team3 = new Team("3 Racing Club", 5);
		div2.addTeam(team3);
		Team team4 = new Team("Sporting No. 4", 6);
		div2.addTeam(team4);
		
		Player player1 = new Player(23, 11, 19);
		team1.addPlayer(player1);
		Player player2 = new Player(22, 23, 9);
		team1.addPlayer(player2);
		Player player3 = new Player(18, 30, 4);
		team1.addPlayer(player3);
		Player player4 = new Player(25, 7, 20);
		team2.addPlayer(player4);
		Player player5 = new Player(19, 12, 3);
		team2.addPlayer(player5);
		Player player6 = new Player(30, 9, 21);
		team2.addPlayer(player6);
		
		Player player7 = new Player(31, 21, 10);
		team3.addPlayer(player7);
		Player player8 = new Player(27, 8, 6);
		team3.addPlayer(player8);
		Player player9 = new Player(28, 17, 7);
		team3.addPlayer(player9);
		Player player10 = new Player(24, 29, 5);
		team4.addPlayer(player10);
		Player player11 = new Player(26, 5, 6);
		team4.addPlayer(player11);
		Player player12 = new Player(29, 26, 11);
		team4.addPlayer(player12);
	}
	// Before uploading this to GitHub I changed the way I wrote some of the variables
	// to make it more clear where they come from while still having
	// the same value, like changing avgTeam1 = 21 to (23 + 22 + 18) / 3.0
	@Test
	public void testGetNumDivisions() {
		int numDivisions = 2;
		assertEquals(numDivisions, stats.getNumDivisions());
	}
	@Test
	public void testGetNumTeams() {
		int numTeams = 4;
		assertEquals(numTeams, stats.getNumTeams());
	}
	@Test
	public void testGetNumGoalsForDivision() {
		int numGoalsDiv1 = 19 + 9 + 4 + 20 + 3 + 21;
		int numGoalsDiv2 = 10 + 6 + 7 + 5 + 6 + 11;
		assertEquals(numGoalsDiv1, stats.getNumGoalsForDivision("Premier Division"));
		assertEquals(numGoalsDiv2, stats.getNumGoalsForDivision("Second Division"));
	}
	@Test
	public void testGetNumGoalsForTeam() {
		int numGoalsTeam1 = 19 + 9 + 4;
		int numGoalsTeam2 = 20 + 3 + 21;
		int numGoalsTeam3 = 10 + 6 + 7;
		int numGoalsTeam4 = 5 + 6 + 11;
		
		assertEquals(numGoalsTeam1, stats.getNumGoalsForTeam("FC 1"));
		assertEquals(numGoalsTeam2, stats.getNumGoalsForTeam("2. FK"));
		assertEquals(numGoalsTeam3, stats.getNumGoalsForTeam("3 Racing Club"));
		assertEquals(numGoalsTeam4, stats.getNumGoalsForTeam("Sporting No. 4"));
	}
	@Test
	public void testGetAverageAgeOfTeam() {
		double avgTeam1 = (23 + 22 + 18) / 3.0;
		double avgTeam2 = (25 + 19 + 30) / 3.0;
		double avgTeam3 = (31 + 27 + 28) / 3.0;
		double avgTeam4 = (24 + 26 + 29) / 3.0;
		
		assertEquals(avgTeam1, stats.getAverageAgeOfTeam("FC 1"), 0);
		assertEquals(avgTeam2, stats.getAverageAgeOfTeam("2. FK"), 0);
		assertEquals(avgTeam3, stats.getAverageAgeOfTeam("3 Racing Club"), 0);
		assertEquals(avgTeam4, stats.getAverageAgeOfTeam("Sporting No. 4"), 0);
	}
	// These next tests check how the methods handle invalid names.
	@Test
	public void testGetNumGoalsForDivisionError() {
		int numGoalsDivError = -1;
		assertEquals(numGoalsDivError, stats.getNumGoalsForDivision("By Zero Division"));
	}
	@Test
	public void testGetNumGoalsForTeamError() {
		int numGoalsTeamError = -1;
		assertEquals(numGoalsTeamError, stats.getNumGoalsForTeam("No Such Team"));
	}
	@Test
	public void testGetAverageAgeOfTeamError() {
		double avgTeamError = -1;
		assertEquals(avgTeamError, stats.getNumGoalsForTeam("No Such Team"), 0);
	}
}
