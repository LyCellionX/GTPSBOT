#pragma once
#include "World.h"
#include <string>
#include <dpp/unicode_emoji.h>

dpp::cluster bot("INPUT YOUR BOT TOKEN HERE", dpp::i_default_intents | dpp::i_message_content);
dpp::snowflake guild_ = 819127381283123; //Input your discord Server ID
dpp::snowflake channel_id = 12528123330999; //input your bot command channel id here
vector<thread> tasks;


string get_file(string location) {
	string returncontent;
	bool found = false;
	ifstream MyReadFile2(location);
	while (getline(MyReadFile2, returncontent)) {
		returncontent = returncontent;
		found = true;
		return returncontent;
	}
	if (!found) {
		return "no_data";
	}
}




/*void AAP2(ENetPeer* peer) {
	if (not pInfo(peer)->cheater_) pInfo(peer)->cheater_ = 1;
	if (pInfo(peer)->vip) pInfo(peer)->rb = 0;
	has_playmod2(pInfo(peer), 76, 1);
	pInfo(peer)->name_color = (pInfo(peer)->whitelist_role ? "`6@" : pInfo(peer)->superdev ? "`s@" : pInfo(peer)->dev ? "`9@" : (pInfo(peer)->mod == 1) ? "`#@" : "`0");
	int on_ = 0;
	{
		vector<string> friends_;
		gamepacket_t p, p_g;
		p.Insert("OnConsoleMessage"), p.Insert("`3FRIEND ALERT:`` " + pInfo(peer)->tankIDName + " has `2logged on``.");
		p_g.Insert("OnConsoleMessage"), p_g.Insert("`5[GUILD ALERT]`` " + pInfo(peer)->tankIDName + " has `2logged on``.");
		for (int c_ = 0; c_ < pInfo(peer)->friends.size(); c_++) friends_.push_back(to_lower(pInfo(peer)->friends[c_].name));
		for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
			if (currentPeer->state != ENET_PEER_STATE_CONNECTED or currentPeer->data == NULL or pInfo(currentPeer)->temp_radio) continue;
			if (pInfo(peer)->guild_id != 0) {
				if (pInfo(peer)->guild_id == pInfo(currentPeer)->guild_id) p_g.CreatePacket(currentPeer);
			}
			if (find(friends_.begin(), friends_.end(), to_lower(pInfo(currentPeer)->tankIDName)) != friends_.end()) {
				if (not pInfo(peer)->invis and not pInfo(peer)->m_h) {
					if (pInfo(currentPeer)->show_friend_notifications_) packet_(currentPeer, "action|play_sfx\nfile|audio/friend_logon.wav\ndelayMS|0"), p.CreatePacket(currentPeer);
				}
				on_++;
			}
		}
	}
	{
		if (pInfo(peer)->Fav_Items.size() != 0) {
			vector<string> Fav_Item_List;
			for (int i = 0; i < pInfo(peer)->Fav_Items.size(); i++) Fav_Item_List.push_back(to_string(pInfo(peer)->Fav_Items[i]));
			gamepacket_t p;
			p.Insert("OnSendFavItemsList");
			p.Insert(join(Fav_Item_List, ","));
			p.Insert(20);
			p.CreatePacket(peer);
		}
	}

	form_emoji(peer);
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	if (pInfo(peer)->hit_by) if (not has_playmod2(pInfo(peer), 136)) pInfo(peer)->hit_by = 0;
	if (pInfo(peer)->grow_reset_week - time(nullptr) <= 0) {
		pInfo(peer)->grow_reset_week = time(nullptr) + 604800;
		pInfo(peer)->grow4good_seed = small_seed_pack[rand() % small_seed_pack.size()];
		pInfo(peer)->grow4good_seed2 = 0, pInfo(peer)->grow4good_combine = 0;
	}
	if (pInfo(peer)->grow_reset_month - time(nullptr) <= 0) {
		pInfo(peer)->grow_reset_month = time(nullptr) + 2592000;
		pInfo(peer)->grow4good_crystal = 0;
		pInfo(peer)->grow4good_gems = 0;
		pInfo(peer)->grow4good_email = 0;
	}
	if (pInfo(peer)->grow4good_gems == -1) pInfo(peer)->grow4good_gems = 0;
	if (pInfo(peer)->surgery_type == -1) pInfo(peer)->surgery_type = rand() % 31;
	SendReceive(peer);
	OnSetVoucher(peer);
	send_inventory(peer);
	update_clothes_value(peer);
	update_clothes_value(peer, true);
	if (pInfo(peer)->playtime_items.size() < 5) {
		int hours_ = ((time(NULL) - pInfo(peer)->playtime) + pInfo(peer)->seconds) / 3600, delay = 0;
		if (hours_ > 300) {
			for (int i = 0; i < play_items.size(); i++) {
				if (find(pInfo(peer)->playtime_items.begin(), pInfo(peer)->playtime_items.end(), play_items[i].first) == pInfo(peer)->playtime_items.end() && hours_ >= play_items[i].second) {
					int get_him = 1;
					if (modify_inventory(peer, play_items[i].first, get_him) == 0) {
						pInfo(peer)->playtime_items.push_back(play_items[i].first);
						gamepacket_t p(delay), p2(delay);
						p.Insert("OnAddNotification"), p.Insert("interface/large/friend_button.rttex"), p.Insert("You've unlocked `$" + items[play_items[i].first].ori_name + "``!"), p.Insert("audio/hub_open.wav"), p.Insert(0), p.CreatePacket(peer);
						p2.Insert("OnConsoleMessage"), p2.Insert("You've unlocked `$" + items[play_items[i].first].ori_name + "``!"), p2.CreatePacket(peer);
						delay += 2000;
					}
				}
			}
		}
	}
	if (not has_playmod2(pInfo(peer), 143)) {
		if (pInfo(peer)->cheater_ == 0) {
			pInfo(peer)->cheater_settings = 0;
			pInfo(peer)->chat_prefix.clear();
		}
	}
	gamepacket_t p1;
	p1.Insert("OnConsoleMessage"), p1.Insert("Welcome back, `w" + get_player_nick(peer) + "``." + (pInfo(peer)->friends.size() == 0 ? "" : (on_ != 0 ? " `w" + to_string(on_) + "`` friend is online." : " No friends are online."))), p1.CreatePacket(peer);
	if (x_gems > 1) variants::OnConsoleMessage(peer, "``[`9Event``] There is currently `2" + to_string(x_gems) + "x ``gems event!");
	//p2.Insert("OnConsoleMessage"), p2.Insert("`2Goals event``: Start working on your goals, you can be farmer, geiger hunter, take providers to receive prizes for leveling up. You will be able to claim your rewards at the end of the week!"), p2.CreatePacket(peer);
	/*{
		gamepacket_t p;
		p.Insert("OnConsoleMessage");
		if (thedaytoday == 1) p.Insert("`3Today is Trees Day!`` 50% higher chance to get `2extra block`` from harvesting tree.");
		else if (thedaytoday == 2) p.Insert("`3Today is Breaking Day!`` 15% higher chance to get `2extra seed``.");
		else if (thedaytoday == 3) p.Insert("`3Today is Geiger Day!`` Higher chance of getting a `2better Geiger prize`` & Irradiated mod will last only `210 minutes``.");
		else if (thedaytoday == 4) p.Insert("`3Today is Tasks Day!`` Get extra `210`` points for completing a task.");
		else if (thedaytoday == 5) p.Insert("`3Today is Gems Day!`` 50% higher chance to get `2extra`` gem drop.");
		else if (thedaytoday == 6) p.Insert("`3Today is Surgery Day!`` Malpractice takes `215 minutes`` and Recovering takes `230 minutes`` & receive `2different prizes``.");
		else if (thedaytoday == 0) p.Insert("`3Today is Fishing Day!`` Catch a fish and receive `2extra lb``.");
		p.CreatePacket(peer);
	}*/

	//if (can_event == false) {
	//	gamepacket_t p3;
	//	p3.Insert("OnConsoleMessage"), p3.Insert("CP:_PL:0_OID:_CT:[S]_ `5***`` `9Seasonal Clash event has started: " + items[event_item].hand_scythe_text + " - " + items[event_item].description + "``"), p3.CreatePacket(peer);
	//}

	//if (beach_party_game) {
		//gamepacket_t p4;
		//p4.Insert("OnConsoleMessage"), p4.Insert("Welcome to Beach Party!"), p4.CreatePacket(peer);
	//}

	//{
		//gamepacket_t p4;
		//p4.Insert("OnConsoleMessage"), p4.Insert("`6It's `4Halloween!`` `6Visit the world `4GROWGANOTH `6to sacrifice your items to Almighty Growganoth``!"), p4.CreatePacket(peer);
	//}

	/*
	{
		gamepacket_t p;
		p.Insert("OnProgressUISet"), p.Insert(1), p.Insert(0), p.Insert(0), p.Insert(0), p.Insert(""), p.Insert(1);
		p.CreatePacket(peer);
		gamepacket_t p4;
		p4.Insert("OnConsoleMessage"), p4.Insert("`2It's Voucher Dayz Weekend in Growtopia! There are some awesome deals in the store so check them out!``"), p4.CreatePacket(peer);
	}*/
	/*
	* 										{
		gamepacket_t p4;
		p4.Insert("OnConsoleMessage"), p4.Insert("Growtopians have collectively eaten `2"+setGems(total_pineapple_eaten) + "`` `9Pineapples!``"), p4.CreatePacket(peer);
	}
	{
		gamepacket_t p4;
		p4.Insert("OnConsoleMessage"), p4.Insert("`3It's Approximately`` `2Cinco`` `wDe`` `4Mayo!`` `wParty with your friends and smash Pinatas for prizes!``"), p4.CreatePacket(peer);
	}
	{
		gamepacket_t p4;
		p4.Insert("OnConsoleMessage"), p4.Insert("The `2Balloon Warz`` are here! Go splat some fools" + Balloon_Warz.balloon_leaderboard2 + "\nYou are in `$Team`` `" + get_balloon_team(pInfo(peer)->balloon_faction) + "``"), p4.CreatePacket(peer);
	}
	*/
	/*
	{
		gamepacket_t p;
		p.Insert("OnProgressUISet"), p.Insert(1), p.Insert(10756), p.Insert(pInfo(peer)->egg_carton), p.Insert(20), p.Insert(""), p.Insert(1);
		p.CreatePacket(peer);
		gamepacket_t p3;
		p3.Insert("OnConsoleMessage"), p3.Insert("`3It's Easter Week!`` Find Magic Eggs hidden in every world, then plant or splice them to make magical springtime items!``"), p3.CreatePacket(peer);
	}*/
	//	p5.Insert("OnConsoleMessage"), p5.Insert("`6It's `wWinterFest!`` Visit the world `2GROWCH`` to meet the evil Growch, and warm his icy heart!``"), p5.CreatePacket(peer);
		//p4.Insert("OnConsoleMessage"), p4.Insert("`2Winter Growch:`` `3Growtopians have collectively feeded " + to_string(winterfest_gift) + "`` `2Winter Gift's`` `3and reached " + to_string(winterfest_gift) + "/500, for every 500`` `2Growch`` `3gives random prizes for everyone!``"), p4.CreatePacket(peer);
		//p5.Insert("OnConsoleMessage"), p5.Insert("Exclusive Black Friday `wCashback Coupons`` now available from buying "+ black_friday_item +". This only lasts for few hours, so hurry up!"), p5.CreatePacket(peer);


	//	p5.Insert("OnConsoleMessage"), p5.Insert("`2Growtopia is a year older!`` Get `5100%`` more Gems and `5Bonus Golden Party Boxes`` for your money this week, and enjoy special party events!"), p5.CreatePacket(peer);
	/*
		gamepacket_t p6;
		p6.Insert("OnConsoleMessage"), p6.Insert("Growtopians have collectively sacrificed `2"+setGems(halloween_rarity)+"`` `9Rarity`` from the GROWGANOTH! Growganoth is pleased and unleashes the corrupted `2Demon Cow Cube`` upon Growtopia!"), p6.CreatePacket(peer);
		*/
		/*int subs = 0;
		has_subscribtion(pInfo(peer), subs);
		if (pInfo(peer)->grow_reset_day - time(nullptr) <= 0) {
			pInfo(peer)->grow_reset_day = time(nullptr) + 86400;
			pInfo(peer)->growpass_quests.clear();
			pInfo(peer)->last_rated.clear();
			pInfo(peer)->w_w = 0;
			pInfo(peer)->grow4good_30mins = (rand() % 3 < 1 ? 0 : -1), pInfo(peer)->grow4good_surgery = (rand() % 3 < 1 ? 0 : -1), pInfo(peer)->grow4good_fish = (rand() % 3 < 1 ? 0 : -1), pInfo(peer)->grow4good_place = (rand() % 3 < 1 ? 0 : -1), pInfo(peer)->grow4good_break = (rand() % 3 < 1 ? 0 : -1), pInfo(peer)->grow4good_trade = (rand() % 3 < 1 ? 0 : -1), pInfo(peer)->grow4good_sb = (rand() % 3 < 1 ? 0 : -1), pInfo(peer)->grow4good_enter = false;
			pInfo(peer)->grow4good_provider = (rand() % 3 < 1 ? 0 : -1);
			pInfo(peer)->grow4good_provider2 = (pInfo(peer)->grow4good_provider == -1 ? -1 : rand() % 450 + 1);
			pInfo(peer)->grow4good_geiger = (rand() % 3 < 1 ? 0 : -1);
			pInfo(peer)->grow4good_geiger2 = (pInfo(peer)->grow4good_geiger == -1 ? -1 : rand() % 7 + 1);
			pInfo(peer)->dd = 0;
			pInfo(peer)->growtoken_worlds.clear();
			if (pInfo(peer)->mod || pInfo(peer)->dev) {
				vector<int> list2{ 408, 274, 276, 408, 274, 276, 408, 274, 276, 278 };
				int receive = 1, item = list2[rand() % list2.size()];
				if (modify_inventory(peer, item, receive) == 0) {
					gamepacket_t p, p2;
					p.Insert("OnConsoleMessage"), p.Insert("Your mod appreciation bonus (feel free keep, trade, or use for prizes) for today is:"), p.CreatePacket(peer);
					p2.Insert("OnConsoleMessage"), p2.Insert("Given `01 " + items[item].name + "``."), p2.CreatePacket(peer);

				}
			}
			if (subs != 0) receive_subscribtion(peer, subs);
		}

		world_menu(peer);
		if (pInfo(peer)->gp) {
			gamepacket_t p;
			p.Insert("OnPaw2018SkinColor1Changed");
			p.Insert(1);
			p.CreatePacket(peer);
			{
				gamepacket_t p;
				p.Insert("OnPaw2018SkinColor2Changed");
				p.Insert(1);
				p.CreatePacket(peer);
			}
			complete_gpass_task(peer, "Claim 4,000 gems");
		}
		if (newtime.tm_hour >= 12 && newtime.tm_hour < 20) {
			if (not has_playmod2(pInfo(peer), 150)) add_playmod(peer, 150);
		}
		else has_playmod2(pInfo(peer), 150, 1);
		if ((not pInfo(peer)->temp_password.empty() && pInfo(peer)->temp_password == pInfo(peer)->tankIDPass) or pInfo(peer)->new_pass == false) {
			gamepacket_t p;
			p.Insert("OnDialogRequest");
			p.Insert("set_default_color|`o\nadd_label_with_icon|big|`0Account Security``|left|1424|\nadd_spacer|small|\nadd_textbox|`6Information``|left|\nadd_smalltext|A hacker may attempt to access your account more than once over a period of time.|left|\nadd_smalltext|Changing your password `2often reduces the risk that they will have frequent access``.|left|\nadd_spacer|small|\nadd_smalltext|Type your new `5password``|left|\nadd_text_input|change|||18|\nend_dialog|change_password||Continue|\n");
			p.CreatePacket(peer);
			pInfo(peer)->temp_password = "";
		}
		else {
			if (pInfo(peer)->gender.empty()) {
				gamepacket_t p;
				p.Insert("OnDialogRequest");
				p.Insert("set_default_color|`o\nadd_label_with_icon|big|`wGender Selection``|left|7612|\nadd_spacer|small|\nadd_textbox|Select your gender:|left|\ntext_scaling_string|5,000ZB|\nadd_button_with_icon|man|Man|noflags|9834|\nadd_button_with_icon|woman|Woman|noflags|9836|\nadd_button_with_icon||END_LIST|noflags|0||\nend_dialog|gender|||");
				p.CreatePacket(peer);
			}
			else news(peer);
		}
	}*/

void readVerification(const dpp::slashcommand_t& Dppevent, string code) {
	string path = "players";
	try {
		for (const auto& entry : fs::directory_iterator(path)) {
			fs::path p{ entry.path() };
			string path_string{ p.string() };
			string fileContent = get_file(path_string);
			if (fileContent != "no_data") {
				json j = json::parse(fileContent);
				string codeFound = (!(j.find("verCode") != j.end()) ? "" : j["verCode"].get<string>());
				bool DiscordVerified = (!(j.find("DiscordVerified") != j.end()) ? false : j["DiscordVerified"].get<bool>());
				string name = (!(j.find("name") != j.end()) ? "" : j["name"].get<string>());
				if (code == codeFound && !DiscordVerified) {
					j["verCode"] = "";
					j["DiscordId"] = to_string(Dppevent.command.get_issuing_user().id);
					j["DiscordVerified"] = true;
					j["DiscordTag"] = Dppevent.command.get_issuing_user().username + "#" + to_string(Dppevent.command.get_issuing_user().discriminator);
					Dppevent.reply("Correct code provided! You're now linked as " + name + ".");
					ofstream save("players/" + name + "_.json");

					if (save.fail()) {
						cout << "Error while writing database" << endl;
						return;
					}
					save << j.dump(4) << endl;
					save.close();
					return;
				}
			}
		}
		Dppevent.reply("Sorry, I was unable to verify you since I am unable to verify that the code is valid. Contact staff if you need help or believe this is a mistake.");
		return;
	}
	catch (...) {
		cout << "Error occured in verification system";
	}
}
void UpdateStatus()
{
	while (true) {
		this_thread::sleep_for(5s);
		int online = 0, donline = -1;
		ofstream w("online.txt"); string text;
		for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
			if (currentPeer->state != ENET_PEER_STATE_CONNECTED or currentPeer->data == NULL or pInfo(currentPeer)->tankIDName == "" or pInfo(currentPeer)->m_h or pInfo(currentPeer)->invis) continue;
			//online++;

			if (server_port == 17091 and secret_standopowah) online += 1 + 2;
			else online += 1;
			text += pInfo(currentPeer)->tankIDName + "\n";

		}
		w << text;

		if (donline not_eq online) {
			donline = online;
			bot.set_presence(dpp::presence(dpp::ps_idle, dpp::at_competing, server_name + " with " + to_string(online) + " player(s)"));
		}
		else donline = -1;
	}
}

void AAP(ENetPeer* peer) {
	gamepacket_t p;
	p.Insert("OnConsoleMessage");
	p.Insert("`4Advance Account Protection`o: You tried to log in to this account that has AAP enabled. Verify yourself in Discord in a moment a message from the Discord bot will ping you to verify before you can continue playing.");
	p.CreatePacket(peer);
}


const enum command { giveitem, verify, role, stop, online, gemevent, gems, ban, unban, stats, economy, changepassword };
class slashcommands {
public:
	static thread update(command command, bool remove = false)
	{
		switch (command) {
		case command::giveitem: {
			dpp::slashcommand giveitem = dpp::slashcommand()
				.set_name("giveitem")
				.set_description("Give items to players.")
				.add_option(dpp::command_option(dpp::co_string, "growid", "the growid of the receiver", true))
				.add_option(dpp::command_option(dpp::co_string, "item", "item id", true))
				.add_option(dpp::command_option(dpp::co_string, "amount", "item amount", true))
				.set_application_id(bot.me.id);
			bot.global_command_create(giveitem, [remove](const auto& callback) {
				dpp::slashcommand command = get<dpp::slashcommand>(callback.value);
				if (not remove) cout << "registered slash command <:" + command.name + ":" + to_string(command.id) + ">" << endl;
				else {
					cout << "deleted slash command <:" + command.name + ":" + to_string(command.id) + ">" << endl;
					bot.global_command_delete_sync(command.id);
				}
				});
			break;
		}
		case command::verify: {
			dpp::slashcommand verify = dpp::slashcommand()
				.set_name("verify")
				.set_description("Use this to verify your discord account to your in-game account, enter the secret code given to you.")
				.add_option(dpp::command_option(dpp::co_string, "secretcode", "Verification code", true))
				.set_application_id(bot.me.id);
			bot.global_command_create(verify, [remove](const auto& callback) {
				dpp::slashcommand command = get<dpp::slashcommand>(callback.value);
				if (not remove) cout << "registered slash command <:" + command.name + ":" + to_string(command.id) + ">" << endl;
				else {
					cout << "deleted slash command <:" + command.name + ":" + to_string(command.id) + ">" << endl;
					bot.global_command_delete_sync(command.id);
				}
				});
			break;
		}
		case command::role: {
			dpp::slashcommand role = dpp::slashcommand()
				.set_name("role")
				.set_description("set role, type 'demote' to remove ALL roles")
				.add_option(dpp::command_option(dpp::co_string, "growid", "the growid of the receiver", true))
				.add_option(dpp::command_option(dpp::co_string, "role", "role name", true))
				.set_application_id(bot.me.id);
			bot.global_command_create(role, [remove](const auto& callback) {
				dpp::slashcommand command = get<dpp::slashcommand>(callback.value);
				if (not remove) cout << "registered slash command <:" + command.name + ":" + to_string(command.id) + ">" << endl;
				else {
					cout << "deleted slash command <:" + command.name + ":" + to_string(command.id) + ">" << endl;
					bot.global_command_delete_sync(command.id);
				}
				});
			break;
		}
		case command::online: {
			dpp::slashcommand online = dpp::slashcommand()
				.set_name("online")
				.set_description("view all players online")
				.set_application_id(bot.me.id);
			bot.global_command_create(online, [remove](const auto& callback) {
				dpp::slashcommand command = get<dpp::slashcommand>(callback.value);
				if (not remove) cout << "registered slash command <:" + command.name + ":" + to_string(command.id) + ">" << endl;
				else {
					cout << "deleted slash command <:" + command.name + ":" + to_string(command.id) + ">" << endl;
					bot.global_command_delete_sync(command.id);
				}
				});
			break;
		}
		case command::gemevent: {
			dpp::slashcommand role = dpp::slashcommand()
				.set_name("gemevent")
				.set_description("1-15x gems event")
				.add_option(dpp::command_option(dpp::co_string, "gems", "how much gems event you want to host?", true))
				.set_application_id(bot.me.id);
			bot.global_command_create(role, [remove](const auto& callback) {
				dpp::slashcommand command = get<dpp::slashcommand>(callback.value);
				if (not remove) cout << "registered slash command <:" + command.name + ":" + to_string(command.id) + ">" << endl;
				else {
					cout << "deleted slash command <:" + command.name + ":" + to_string(command.id) + ">" << endl;
					bot.global_command_delete_sync(command.id);
				}
				});
			break;
		}
		case command::stop: {
			dpp::slashcommand stop = dpp::slashcommand()
				.set_name("stop")
				.set_description("saves server and shuts it")
				.set_application_id(bot.me.id);
			bot.global_command_create(stop, [remove](const auto& callback) {
				dpp::slashcommand command = get<dpp::slashcommand>(callback.value);
				if (not remove) cout << "registered slash command <:" + command.name + ":" + to_string(command.id) + ">" << endl;
				else {
					cout << "deleted slash command <:" + command.name + ":" + to_string(command.id) + ">" << endl;
					bot.global_command_delete_sync(command.id);
				}
				});
			break;
		}
		case command::economy: {
			dpp::slashcommand online = dpp::slashcommand()
				.set_name("economy")
				.set_description("view server's economy")
				.set_application_id(bot.me.id);
			bot.global_command_create(online, [remove](const auto& callback) {
				dpp::slashcommand command = get<dpp::slashcommand>(callback.value);
				if (not remove) cout << "registered slash command <:" + command.name + ":" + to_string(command.id) + ">" << endl;
				else {
					cout << "deleted slash command <:" + command.name + ":" + to_string(command.id) + ">" << endl;
					bot.global_command_delete_sync(command.id);
				}
				});
			break;
		}
		case command::ban: {
			dpp::slashcommand ban = dpp::slashcommand()
				.set_name("ban")
				.set_description("ban someone in-game")
				.add_option(dpp::command_option(dpp::co_string, "growid", "name of person to ban", true))
				.add_option(dpp::command_option(dpp::co_string, "length", "how long there banned for (minutes)", true))
				.set_application_id(bot.me.id);
			bot.global_command_create(ban, [remove](const auto& callback) {
				dpp::slashcommand command = get<dpp::slashcommand>(callback.value);
				if (not remove) cout << "registered slash command <:" + command.name + ":" + to_string(command.id) + ">" << endl;
				else {
					cout << "deleted slash command <:" + command.name + ":" + to_string(command.id) + ">" << endl;
					bot.global_command_delete_sync(command.id);
				}
				});
			break;
		}
		case command::gems: {
			dpp::slashcommand givegems = dpp::slashcommand()
				.set_name("givegems")
				.set_description("give someone gems in game")
				.add_option(dpp::command_option(dpp::co_string, "growid", "name of person to give gems", true))
				.add_option(dpp::command_option(dpp::co_string, "amount", "how much gems", true))
				.set_application_id(bot.me.id);
			bot.global_command_create(givegems, [remove](const auto& callback) {
				dpp::slashcommand command = get<dpp::slashcommand>(callback.value);
				if (not remove) cout << "registered slash command <:" + command.name + ":" + to_string(command.id) + ">" << endl;
				else {
					cout << "deleted slash command <:" + command.name + ":" + to_string(command.id) + ">" << endl;
					bot.global_command_delete_sync(command.id);
				}
				});
			break;
		}
		case command::unban: {
			dpp::slashcommand unban = dpp::slashcommand()
				.set_name("unban")
				.set_description("unban someone in-game")
				.add_option(dpp::command_option(dpp::co_string, "growid", "name of person to unban", true))
				.set_application_id(bot.me.id);
			bot.global_command_create(unban, [remove](const auto& callback) {
				dpp::slashcommand command = get<dpp::slashcommand>(callback.value);
				if (not remove) cout << "registered slash command <:" + command.name + ":" + to_string(command.id) + ">" << endl;
				else {
					cout << "deleted slash command <:" + command.name + ":" + to_string(command.id) + ">" << endl;
					bot.global_command_delete_sync(command.id);
				}
				});
			break;
		}
		case command::stats: {
			dpp::slashcommand stats = dpp::slashcommand()
				.set_name("stats")
				.set_description("check someone's stats in-game")
				.add_option(dpp::command_option(dpp::co_string, "growid", "name of person to check", true))
				.set_application_id(bot.me.id);
			bot.global_command_create(stats, [remove](const auto& callback) {
				dpp::slashcommand command = get<dpp::slashcommand>(callback.value);
				if (not remove) cout << "registered slash command <:" + command.name + ":" + to_string(command.id) + ">" << endl;
				else {
					cout << "deleted slash command <:" + command.name + ":" + to_string(command.id) + ">" << endl;
					bot.global_command_delete_sync(command.id);
				}
				});
			break;
		}
		case command::changepassword: {
			dpp::slashcommand changepassword = dpp::slashcommand()
				.set_name("changepassword")
				.set_description("change your password in-game")
				.set_application_id(bot.me.id);
			bot.global_command_create(changepassword, [remove](const auto& callback) {
				dpp::slashcommand command = get<dpp::slashcommand>(callback.value);
				if (not remove) cout << "registered slash command <:" + command.name + ":" + to_string(command.id) + ">" << endl;
				else {
					cout << "deleted slash command <:" + command.name + ":" + to_string(command.id) + ">" << endl;
					bot.global_command_delete_sync(command.id);
				}
				});
			break;
		}
		default: break;
		}
		return thread();
	}
	class commands
	{
	public:
		static bool economy(const dpp::slashcommand_t& event) {
			vector<int> itemIds242 = { 242 };
			vector<int> itemIds1796 = { 1796 };
			vector<int> itemIds7188 = { 7188 };

			dpp::embed embed = dpp::embed().set_color(dpp::colors::yellow).set_title(server_name + "'s Economy");

			int totalWLS = 0;
			int totalDLS = 0;
			int totalBGLS = 0;
			multimap<int, string, greater<int>> playerWealth;

			filesystem::path playersDirectory("players");
			if (filesystem::exists(playersDirectory) && filesystem::is_directory(playersDirectory))
			{
				for (const auto& entry : filesystem::directory_iterator(playersDirectory))
				{
					if (entry.is_regular_file())
					{
						string path_ = entry.path().string();
						json j;

						if (_access_s(path_.c_str(), 0) == 0)
						{
							ifstream r(path_, ifstream::binary);
							if (!r.is_open() || r.fail()) continue; // Move to the next player
							r >> j;
							r.close();
							string playerName = j.value("name", "Unknown");
							int owner = j.value("owner", 0);
							json inventory = j.value("inv", json::array());
							string inventoryStr;
							int playerWLS = 0;
							int playerDLS = 0;
							int playerBGLS = 0;

							for (const auto& item : inventory)
							{
								int itemId = item.value("i", 0);
								int itemCount = item.value("c", 0);

								if (std::find(itemIds242.begin(), itemIds242.end(), itemId) != itemIds242.end())
								{
									playerWLS += itemCount;
								}
								else if (std::find(itemIds1796.begin(), itemIds1796.end(), itemId) != itemIds1796.end())
								{
									playerDLS += itemCount;
								}
								else if (std::find(itemIds7188.begin(), itemIds7188.end(), itemId) != itemIds7188.end())
								{
									playerBGLS += itemCount;
								}
							}

							totalWLS += playerWLS;
							totalDLS += playerDLS;
							totalBGLS += playerBGLS;
						}
					}
				}
				embed.add_field("Total WLS:", to_string(totalWLS), false);
				embed.add_field("Total DLS:", to_string(totalDLS), false);
				embed.add_field("Total BGLS:", to_string(totalBGLS), false);

				event.reply(dpp::message(event.command.channel_id, embed).set_reference(event.command.id));
				return true;
			}
		}
		static bool stats(const dpp::slashcommand_t& event)
		{
			string growid = get<string>(event.get_parameter("growid"));
			string path_ = "players/" + growid + "_.json";
			if (_access_s(path_.c_str(), 0) == 0) {
				json j;
				ifstream r(path_, ifstream::binary);
				if (not r.is_open() or r.fail()) return false;
				r >> j; r.close();
				string playerName = j.value("name", "Unknown");
				string discordTag = j.value("DiscordTag", "Unknown");
				bool discordVerified = j.value("DiscordVerified", false);
				int level = j.value("level", 0);
				int gem = j.value("gems", 0);
				json inventory = j.value("inv", json::array());

				string inventoryStr;
				int itemsPerLine = 5; // Number of items to display per line
				string emoji;
				string emoji2;
				for (size_t i = 0; i < inventory.size(); ++i) {
					int itemId = inventory[i].value("i", 0);
					int itemCount = inventory[i].value("c", 0);
					if (itemId && itemCount >= 1) {
						for (const auto& itemInfo : items) {
							if (itemInfo.id == itemId) {
								if (items[itemId].blockType == LOCK) {
									if (itemId == 242) inventoryStr += "**" + itemInfo.name + " [" + to_string(itemCount) + "]**";
									else if (itemId == 1796) inventoryStr += "**" + itemInfo.name + " [" + to_string(itemCount) + "]**";
									else if (itemId == 2408) inventoryStr += "**" + itemInfo.name + " [" + to_string(itemCount) + "]**";
									else if (itemId == 7188) inventoryStr += "**" + itemInfo.name + " [" + to_string(itemCount) + "]**";
									else inventoryStr += " **" + itemInfo.name + " [" + to_string(itemCount) + "]**";
									//inventoryStr += emoji + " **" + itemInfo.name + " [" + to_string(itemCount) + "]**";
									// Add a newline if not the last item on the line
									if ((i + 1) % itemsPerLine != 0 && i != inventory.size() - 1) {
										inventoryStr += ", ";
									}
									else {
										inventoryStr += "\n";
									}
									break;
								}
							}
						}
					}
				}

				ofstream w(path_, ifstream::binary);
				w << j;
				dpp::embed embed = dpp::embed().set_color(dpp::colors::yellow).set_title("Player stats [" + growid + "]");
				embed.add_field("GrowID: ", playerName, true);
				embed.add_field("Discord: ", discordTag, true);
				string verificationStatus = discordVerified ? "Yes" : "No";
				embed.add_field("Discord Verification: ", verificationStatus, true);
				embed.add_field("Level: ", to_string(level), true);
				embed.add_field("Gems: ", to_string(gem), true);
				// Add the entire inventory as a single field with line breaks
				embed.add_field("Inventory: ", inventoryStr, false);
				event.reply(dpp::message(event.command.channel_id, embed).set_reference(event.command.id));
				return true;
			}
		}
		//\nadd_smalltext|IP: `5" + j["ip"].get<string>() + "``|left|\nadd_smalltext|RID: `5Not found.``|left|\nadd_smalltext|MAC Address: `5Not found.``|left|\nadd_smalltext|Country Code: `5Not found.``|left|\nadd_spacer|small\nadd_textbox|`6Assets Info``|left|\nadd_smalltext|Level: `5" + to_string(j["level"].get<int>()) + "``|left|\nadd_smalltext|Gems: `5" + to_string(j["gems"].get<int>()) + "``|left|\nadd_smalltext|XP: `5" + to_string(j["xp"].get<int>()) + "``|left|
		static bool giveitem(const dpp::slashcommand_t& event)
		{
			dpp::snowflake authorizedUserIds[] = { 852610618300825661, 1006964264373862482 };

			bool isAuthorized = false;

			for (dpp::snowflake userId : authorizedUserIds) {
				if (event.command.usr.id == userId) {
					isAuthorized = true;
					break;
				}
			}

			if (!isAuthorized) {
				// Send an error message indicating unauthorized access
				dpp::embed errorEmbed = dpp::embed()
					.set_color(dpp::colors::red)
					.set_description("You are not authorized to use this command.");

				event.reply(dpp::message(event.command.channel_id, errorEmbed).set_reference(event.command.id));

				return false;
			}

			string growid = get<string>(event.get_parameter("growid"));
			int item = stoi(get<string>(event.get_parameter("item")));
			int c_ = stoi(get<string>(event.get_parameter("amount")));
			string path_ = "players/" + growid + "_.json";
			if (_access_s(path_.c_str(), 0) == 0) {
				json j;
				ifstream r(path_, ifstream::binary);
				if (not r.is_open() or r.fail()) return false;
				r >> j;
				for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
					if (currentPeer->state != ENET_PEER_STATE_CONNECTED or currentPeer->data == NULL) continue;
					if (to_lower(growid) == to_lower(pInfo(currentPeer)->tankIDName)) {
						modify_inventory(currentPeer, item, c_);
						console_msg(currentPeer, "`o>> You receieved `1" + to_string(c_) + " " + items[item].name + "`o.");
					}
					dpp::embed embed = dpp::embed().set_color(dpp::colors::yellow).set_description(growid + " was given " + to_string(c_) + " " + items[item].name + ".");
					event.reply(dpp::message(event.command.channel_id, embed).set_reference(event.command.id));
				}
				return true;
			}
		}

		static int verify(const dpp::slashcommand_t& event)
		{
			string code = get<string>(event.get_parameter("secretcode"));
			for (ENetPeer* user = server->peers; user < &server->peers[server->peerCount]; user++) {
				if (user->state != ENET_PEER_STATE_CONNECTED || user->data == NULL) continue;
				if (pInfo(user)->discordPending && pInfo(user)->discordId == code) {
					pInfo(user)->discordPending = false;
					pInfo(user)->discordId.clear();
					pInfo(user)->discordTag = event.command.get_issuing_user().username;
					pInfo(user)->discordVerified = true;
					pInfo(user)->discordDis = to_string(event.command.get_issuing_user().id);
					gamepacket_t p;
					p.Insert("OnAddNotification");
					p.Insert("interface/atomic_button.rttex");
					p.Insert("`wDiscord Account has been verified! (" + pInfo(user)->discordTag + ")");
					p.Insert("audio/hub_open.wav");
					p.Insert(0);
					p.CreatePacket(user);
					event.reply("Account **" + pInfo(user)->tankIDName + "** has been linked to this Discord account (" + pInfo(user)->discordTag + ")! You should receive an in-game notification in a second to setup your 2fa (optional)...");
					dpp::find_guild_member(event.command.get_guild().id, event.command.get_issuing_user().id).set_nickname(pInfo(user)->tankIDName);
					return 1;
				}
			}
			return 0;
		}
		static bool online(const dpp::slashcommand_t& event)
		{
			dpp::snowflake authorizedUserIds[] = { 852610618300825661, 1006964264373862482 };

			bool isAuthorized = false;

			for (dpp::snowflake userId : authorizedUserIds) {
				if (event.command.usr.id == userId) {
					isAuthorized = true;
					break;
				}
			}

			if (!isAuthorized) {
				// Send an error message indicating unauthorized access
				dpp::embed errorEmbed = dpp::embed()
					.set_color(dpp::colors::red)
					.set_description("You are not authorized to use this command.");

				event.reply(dpp::message(event.command.channel_id, errorEmbed).set_reference(event.command.id));

				return false;
			}
			string text; int C = 0;
			for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
				if (currentPeer->state != ENET_PEER_STATE_CONNECTED or currentPeer->data == NULL or pInfo(currentPeer)->tankIDName == "") continue;
				C++;
				text += "" + (pInfo(currentPeer)->tankIDName + ", ");
			}
			if (not text.empty()) text.resize(text.size() - 2);
			else {
				dpp::embed embed = dpp::embed().set_color(dpp::colors::yellow).set_description("seems nobody is online at the moment..").set_timestamp(time(0));
				event.reply(dpp::message(event.command.channel_id, embed).set_reference(event.command.id));
			}
			dpp::embed embed = dpp::embed().set_color(dpp::colors::yellow).set_description("[**" + std::to_string(C) + "**]: " + text).set_timestamp(time(0));
			event.reply(dpp::message(event.command.channel_id, embed).set_reference(event.command.id));
			return true;
		}
		static bool ban(const dpp::slashcommand_t& event)
		{
			dpp::snowflake authorizedUserIds[] = { 852610618300825661, 1006964264373862482 };

			bool isAuthorized = false;

			for (dpp::snowflake userId : authorizedUserIds) {
				if (event.command.usr.id == userId) {
					isAuthorized = true;
					break;
				}
			}

			if (!isAuthorized) {
				// Send an error message indicating unauthorized access
				dpp::embed errorEmbed = dpp::embed()
					.set_color(dpp::colors::red)
					.set_description("You are not authorized to use this command.");

				event.reply(dpp::message(event.command.channel_id, errorEmbed).set_reference(event.command.id));

				return false;
			}

			string growid = get<string>(event.get_parameter("growid"));
			string minutes = get<string>(event.get_parameter("length"));
			long long convert = stoll(minutes) * 60000;
			string path_ = "players/" + growid + "_.json";
			if (_access_s(path_.c_str(), 0) == 0) {
				json j;
				ifstream r(path_, ifstream::binary);
				if (not r.is_open() or r.fail()) return false;
				for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
					if (currentPeer->state != ENET_PEER_STATE_CONNECTED or currentPeer->data == NULL or pInfo(currentPeer)->tankIDName == "Time") continue;
					if (to_lower(growid) == to_lower(pInfo(currentPeer)->tankIDName)) {
						if (pInfo(currentPeer)->b_t + convert < (duration_cast<milliseconds>(system_clock::now().time_since_epoch())).count()) {
							r >> j;

							j["b_t"] = (duration_cast<milliseconds>(system_clock::now().time_since_epoch())).count();
							j["b_s"] = convert;
							j["b_r"] = "No reason attached.";
							j["b_b"] = "SYSTEM";
							ofstream w(path_, ifstream::binary);
							w << j;
							pInfo(currentPeer)->b_t = (duration_cast<milliseconds>(system_clock::now().time_since_epoch())).count();
							pInfo(currentPeer)->b_s = convert;
							pInfo(currentPeer)->b_r = "No reason attached.";
							pInfo(currentPeer)->b_b = "SYSTEM";
							gamepacket_t a, b;
							a.Insert("OnAddNotification"), b.Insert("OnConsoleMessage"); a.Insert("interface/cash_icon_overlay.rttex");
							a.Insert("`0Warning from `4System: `0You have been `4banned!"); a.Insert("audio/hub_open.wav"); a.Insert(0);
							b.Insert("`0Warning from `4System: `0You have been `4banned!");
							a.CreatePacket(currentPeer), b.CreatePacket(currentPeer);
							enet_peer_disconnect_later(currentPeer, 0);
						}
					}
				}
				dpp::embed embed = dpp::embed().set_color(dpp::colors::yellow).set_description("**" + growid + "** has been banned from " + server_name + " for **" + minutes + " minutes**.");
				event.reply(dpp::message(event.command.channel_id, embed).set_reference(event.command.id));
			}
			return true;
		}
		static bool gemevent(const dpp::slashcommand_t& event)
		{
			dpp::snowflake authorizedUserIds[] = { 852610618300825661, 1006964264373862482 };

			bool isAuthorized = false;

			for (dpp::snowflake userId : authorizedUserIds) {
				if (event.command.usr.id == userId) {
					isAuthorized = true;
					break;
				}
			}

			if (!isAuthorized) {
				dpp::embed errorEmbed = dpp::embed()
					.set_color(dpp::colors::red)
					.set_description("You are not authorized to use this command.");

				event.reply(dpp::message(event.command.channel_id, errorEmbed).set_reference(event.command.id));

				return false;
			}

			int gemsevent = stoi(get<string>(event.get_parameter("gems")));
			x_gems = gemsevent;
			if (x_gems < 1) x_gems = 1;
			if (x_gems > 30) x_gems = 30;
			for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
				if (currentPeer->state != ENET_PEER_STATE_CONNECTED or currentPeer->data == NULL) continue;
				if (x_gems <= 1) {
					gamepacket_t a, b;
					a.Insert("OnAddNotification"), b.Insert("OnConsoleMessage"); a.Insert("interface/cash_icon_overlay.rttex");
					a.Insert("`9Gems event ended!"); a.Insert("audio/hub_open.wav"); a.Insert(0);
					b.Insert("``>> `9Gems event ended!");
					a.CreatePacket(currentPeer), b.CreatePacket(currentPeer);

				}
				else {
					gamepacket_t a, b;
					a.Insert("OnAddNotification"), b.Insert("OnConsoleMessage"); a.Insert("interface/cash_icon_overlay.rttex");
					a.Insert("`9" + to_string(gemsevent) + "x gems event started for 1 day!"); a.Insert("audio/hub_open.wav"); a.Insert(0);
					b.Insert("``>> `9" + to_string(gemsevent) + "x gems event started for 1 day!");
					a.CreatePacket(currentPeer), b.CreatePacket(currentPeer);
				}
			}
			if (x_gems <= 1) {
				dpp::embed embed = dpp::embed().set_color(dpp::colors::yellow).set_description("Gems event ended.");
				event.reply(dpp::message(event.command.channel_id, embed).set_reference(event.command.id));
			}
			else {
				dpp::embed embed = dpp::embed().set_color(dpp::colors::yellow).set_description("**" + to_string(gemsevent) + "x** gems event started for 1 day.");
				event.reply(dpp::message(event.command.channel_id, embed).set_reference(event.command.id));
			}
		}
		static bool gems(const dpp::slashcommand_t& event)
		{
			dpp::snowflake authorizedUserIds[] = { 852610618300825661, 1006964264373862482 };

			bool isAuthorized = false;

			for (dpp::snowflake userId : authorizedUserIds) {
				if (event.command.usr.id == userId) {
					isAuthorized = true;
					break;
				}
			}

			if (!isAuthorized) {
				// Send an error message indicating unauthorized access
				dpp::embed errorEmbed = dpp::embed()
					.set_color(dpp::colors::red)
					.set_description("You are not authorized to use this command.");

				event.reply(dpp::message(event.command.channel_id, errorEmbed).set_reference(event.command.id));

				return false;
			}

			string growid = get<string>(event.get_parameter("growid"));
			string gems = get<string>(event.get_parameter("amount"));
			string path_ = "players/" + growid + "_.json";
			if (_access_s(path_.c_str(), 0) == 0) {
				json j;
				ifstream r(path_, ifstream::binary);
				if (not r.is_open() or r.fail()) return false;
				if (gems.find_first_not_of("0123456789") != string::npos) return false;
				for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
					if (currentPeer->state != ENET_PEER_STATE_CONNECTED or currentPeer->data == NULL) continue;
					if (to_lower(growid) == to_lower(pInfo(currentPeer)->tankIDName)) {
						pInfo(currentPeer)->gems += atoi(gems.c_str());
						gamepacket_t p;
						p.Insert("OnSetBux"), p.Insert(pInfo(currentPeer)->gems), p.Insert(0), p.Insert((pInfo(currentPeer)->supp >= 1) ? 1 : 0);
						if (pInfo(currentPeer)->supp >= 2) p.Insert((float)33796, (float)1, (float)0);
						p.CreatePacket(currentPeer);
						gamepacket_t a, b;
						a.Insert("OnAddNotification"), b.Insert("OnConsoleMessage"); a.Insert("interface/cash_icon_overlay.rttex");
						a.Insert("`0You received `2" + gems + " `0gems!"); a.Insert("audio/hub_open.wav"); a.Insert(0);
						b.Insert(">> `0You received `2" + gems + " `0gems!");
						a.CreatePacket(currentPeer), b.CreatePacket(currentPeer);
					}
				}
				dpp::embed embed = dpp::embed().set_color(dpp::colors::yellow).set_description("**Gave " + gems + " gems(s) to " + growid + ".**");
				event.reply(dpp::message(event.command.channel_id, embed).set_reference(event.command.id));
			}
			return true;
		}
		static bool unban(const dpp::slashcommand_t& event)
		{
			dpp::snowflake authorizedUserIds[] = { 852610618300825661, 1006964264373862482 };

			bool isAuthorized = false;

			for (dpp::snowflake userId : authorizedUserIds) {
				if (event.command.usr.id == userId) {
					isAuthorized = true;
					break;
				}
			}

			if (!isAuthorized) {
				dpp::embed errorEmbed = dpp::embed()
					.set_color(dpp::colors::red)
					.set_description("You are not authorized to use this command.");

				event.reply(dpp::message(event.command.channel_id, errorEmbed).set_reference(event.command.id));

				return false;
			}

			string growid = get<string>(event.get_parameter("growid"));
			string path_ = "players/" + growid + "_.json";
			if (_access_s(path_.c_str(), 0) == 0) {
				json j;
				ifstream r(path_, ifstream::binary);
				if (not r.is_open() or r.fail()) return false;
				r >> j; r.close();
				j["b_t"] = 0;
				j["b_s"] = 0;
				j["b_r"] = "";
				j["b_b"] = "";
				ofstream w(path_, ifstream::binary);
				w << j;
				for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
					if (currentPeer->state != ENET_PEER_STATE_CONNECTED or currentPeer->data == NULL) continue;
					if (to_lower(growid) == to_lower(pInfo(currentPeer)->tankIDName)) {
						pInfo(currentPeer)->b_t = 0;
						pInfo(currentPeer)->b_s = 0;
						pInfo(currentPeer)->b_r = "";
						pInfo(currentPeer)->b_b = "";
					}
				}
				dpp::embed embed = dpp::embed().set_color(dpp::colors::yellow).set_description(growid + " has been unbanned from " + server_name);
				event.reply(dpp::message(event.command.channel_id, embed).set_reference(event.command.id));
			}
			return true;
		}

		static bool changepassword(const dpp::slashcommand_t& event)
		{
			dpp::interaction_modal_response modal("my_modal", "Password Recovery");
			modal.add_component(dpp::component().
				set_label("enter the email")
				.set_id("1").
				set_type(dpp::cot_text).
				set_placeholder("example@gmail.com").
				set_min_length(1).
				set_max_length(80).
				set_text_style(dpp::text_short));
			modal.add_row();
			modal.add_component(dpp::component().
				set_label("enter the growid")
				.set_id("2").
				set_type(dpp::cot_text).
				set_placeholder("").
				set_min_length(1).
				set_max_length(80).
				set_text_style(dpp::text_short));
			modal.add_row();
			modal.add_component(dpp::component().
				set_label("enter the new password")
				.set_id("3").
				set_type(dpp::cot_text).
				set_placeholder("").
				set_min_length(1).
				set_max_length(80).
				set_text_style(dpp::text_short));
			event.dialog(modal);
			return true;
		}
	};
};
static int find_command(string command)
{
	if (command == "giveitem") return command::giveitem;
	if (command == "verify") return command::verify;
	if (command == "role") return command::role;
	if (command == "gemevent") return command::gemevent;
	if (command == "online") return command::online;
	if (command == "ban") return command::ban;
	if (command == "economy") return command::economy;
	if (command == "givegems") return command::gems;
	if (command == "unban") return command::unban;
	if (command == "stats") return command::stats;
	if (command == "changepassword") return command::changepassword;
}
void bot_gateway() {

	//bot.on_log(dpp::utility::cout_logger());
	bot.on_log([&](const dpp::log_t& event) {
		ofstream w("dpp_log.txt", ios::app);
		});
	bot.on_ready([&](const dpp::ready_t& event) {
		if (dpp::run_once<struct register_bot_commands>()) {
			;
			dpp::slashcommand verifycommand("verify", "Verify yourself", bot.me.id);
			verifycommand.add_option(
				dpp::command_option(dpp::co_string, "secretcode", "Enter your verification code", true)
			);

			dpp::slashcommand gemseventcommand("gemevent", "Host gems event ", bot.me.id);
			gemseventcommand.add_option(
				dpp::command_option(dpp::co_string, "gems", "How many gems event?", true)
			);

			dpp::slashcommand newcommand("ban", "Bans a player from " + server_name, bot.me.id);
			newcommand.add_option(
				dpp::command_option(dpp::co_string, "growid", "Who would you like to ban?", true)
			);
			newcommand.add_option(
				dpp::command_option(dpp::co_string, "length", "How long would the person be banned? (Time in minutes)", true)
			);

			dpp::slashcommand gemcommand("givegems", "Gives gems to a player in " + server_name, bot.me.id);
			gemcommand.add_option(
				dpp::command_option(dpp::co_string, "growid", "Who would you like to give gems to?", true)
			);
			gemcommand.add_option(
				dpp::command_option(dpp::co_string, "amount", "How much gems you want to give the player?", true)
			);
			dpp::slashcommand rolecommand("role", "Set role, type 'demote' to remove ALL roles", bot.me.id);
			rolecommand.add_option(
				dpp::command_option(dpp::co_string, "growid", "Who would you like to promote/demote?", true)
			);
			rolecommand.add_option(
				dpp::command_option(dpp::co_string, "role", "What role should person receive?", true)
			);

			dpp::slashcommand givecommand("giveitem", "give item to a specific player in " + server_name, bot.me.id);
			givecommand.add_option(
				dpp::command_option(dpp::co_string, "growid", "Who would you like to give item?", true)
			);
			givecommand.add_option(
				dpp::command_option(dpp::co_string, "item", "What item would you like to give?", true)
			);
			givecommand.add_option(
				dpp::command_option(dpp::co_string, "amount", "How much would you like to give?", true)
			);

			dpp::slashcommand unbancommand("unban", "Unbans a player from " + server_name, bot.me.id);
			unbancommand.add_option(
				dpp::command_option(dpp::co_string, "growid", "Who would you like to unban?", true)
			);

			dpp::slashcommand stats("stats", "Checks a player's info from " + server_name, bot.me.id);
			stats.add_option(
				dpp::command_option(dpp::co_string, "growid", "Who would you like to check?", true)
			);

			bot.global_command_create(
				dpp::slashcommand("changepassword", "Change your password with that!", bot.me.id)
			);
			bot.global_command_create(
				dpp::slashcommand("online", "Check, who is online at the moment.", bot.me.id)
			);
			bot.global_command_create(
				dpp::slashcommand("economy", "Check, server's economy.", bot.me.id)
			);


			bot.global_command_create(newcommand);
			bot.global_command_create(verifycommand);
			bot.global_command_create(gemseventcommand);
			bot.global_command_create(givecommand);
			bot.global_command_create(rolecommand);
			bot.global_command_create(unbancommand);
			bot.global_command_create(stats);
			bot.global_command_create(gemcommand);
			cout << "Bot Discord Started Credit :LyCellionX & Time >> Don't Delete pls :) " << endl;
		}
		});
	bot.on_slashcommand([&](const dpp::slashcommand_t& event) {
		switch (find_command(event.command.get_command_name()))
		{
		case command::verify: {
			future<int> verifyUser = async(slashcommands::commands::verify, event);
			verifyUser.wait();
			if (verifyUser.get() != 1) {
				string code = get<string>(event.get_parameter("secretcode"));
				std::thread tryCheckOff(readVerification, event, code);
				tryCheckOff.detach();
				return;
			}
			return;
		}
		case command::online: {
			future<bool> online = async(slashcommands::commands::online, event);
			online.wait();
			if (not online.get()) return;
			break;
		}

		case command::economy: {
			future<bool> eco = async(slashcommands::commands::economy, event);
			eco.wait();
			if (not eco.get()) return;
			break;
		}
		case command::gemevent: {
			future<bool> gemevents = async(slashcommands::commands::gemevent, event);
			gemevents.wait();
			if (not gemevents.get()) return;
			break;
		}

		case command::ban: {
			future<bool> ban = async(slashcommands::commands::ban, event);
			ban.wait();
			if (not ban.get()) {
				dpp::embed embed = dpp::embed().set_color(dpp::colors::yellow).set_description("ban function returned false. invalid growid?");
				bot.message_create(dpp::message(event.command.channel_id, embed)
					.set_reference(event.command.id)
					.set_flags(dpp::m_ephemeral));
				return;
			}
			break;
		}
		case command::gems: {
			future<bool> givegems = async(slashcommands::commands::gems, event);
			givegems.wait();
			if (not givegems.get()) {
				dpp::embed embed = dpp::embed().set_color(dpp::colors::yellow).set_description("givegems function returned false. invalid growid?");
				bot.message_create(dpp::message(event.command.channel_id, embed)
					.set_reference(event.command.id)
					.set_flags(dpp::m_ephemeral));
				return;
			}
			break;
		}
		case command::giveitem: {
			future<bool> giveitems = async(slashcommands::commands::giveitem, event);
			giveitems.wait();
			if (not giveitems.get()) {
				dpp::embed embed = dpp::embed().set_color(dpp::colors::yellow).set_description("giveitem function returned false. invalid growid?");
				bot.message_create(dpp::message(event.command.channel_id, embed)
					.set_reference(event.command.id)
					.set_flags(dpp::m_ephemeral));
				return;
			}
			break;
		}
		case command::unban: {
			future<bool> unban = async(slashcommands::commands::unban, event);
			unban.wait();
			if (not unban.get()) {
				dpp::embed embed = dpp::embed().set_color(dpp::colors::yellow).set_description("unban function returned false. invalid growid?");
				bot.message_create(dpp::message(event.command.channel_id, embed)
					.set_reference(event.command.id)
					.set_flags(dpp::m_ephemeral));
				return;
			}
			break;
		}
		case command::stats: {
			future<bool> stats = async(slashcommands::commands::stats, event);
			stats.wait();
			if (not stats.get()) {
				dpp::embed embed = dpp::embed().set_color(dpp::colors::yellow).set_description("stats function returned false. invalid growid?");
				bot.message_create(dpp::message(event.command.channel_id, embed)
					.set_reference(event.command.id)
					.set_flags(dpp::m_ephemeral));
				return;
			}
			break;
		}
		case command::changepassword: {
			future<bool> changepassword = async(slashcommands::commands::changepassword, event);
			changepassword.wait();
			if (not changepassword.get()) return;
			break;
		}
		default: break;
		}
		});
	bot.on_button_click([&](const dpp::button_click_t& event) {
		for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
			if (currentPeer->state != ENET_PEER_STATE_CONNECTED or currentPeer->data == NULL) continue;
			if (event.custom_id == "verify_button") {
				if (to_string(event.command.get_issuing_user().id) == pInfo(currentPeer)->discordDis) {
					event.reply(dpp::message("Verification successfull logging u in..").set_flags(dpp::m_ephemeral));
				}
				else if (to_string(event.command.get_issuing_user().id) != pInfo(currentPeer)->discordDis) {
					event.reply(dpp::message("You can't verify others to login... Only your own account that is linked is possible").set_flags(dpp::m_ephemeral));
				}
			}
		}
		});

	bot.on_form_submit([&](const dpp::form_submit_t& event) {
		string f1 = get<string>(event.components[0].components[0].value);
		string f2 = get<string>(event.components[1].components[0].value);
		string f3 = get<string>(event.components[2].components[0].value);
		string email = "";
		string path_ = "players/" + f2 + "_.json";
		json j;
		ifstream r(path_, ifstream::binary);
		if (r.fail() or not r.is_open()) {
			dpp::message m;
			m.set_content("This GrowID doesn't exsist...").set_flags(dpp::m_ephemeral);
			event.reply(m);
		}
		else {
			r >> j;
			email = j["email"];
			if (email not_eq f1) {
				dpp::message m;
				m.set_content("the email does not match the account's email.").set_flags(dpp::m_ephemeral);
				event.reply(m);
			}
			else {
				string path_ = "players/" + f2 + "_.json";
				json j;
				ifstream r(path_, ifstream::binary);
				if (r.fail() or not r.is_open()) event.reply("invalid growid");
				else {
					r >> j;
					j["pass"] = f3;
					ofstream w(path_, ifstream::binary);
					w << j;
					dpp::message m;
					m.set_content("Password successfully changed to " + f3).set_flags(dpp::m_ephemeral);
					event.reply(m);
				}
			}
		}
		});

	bot.start(dpp::st_wait);
}
