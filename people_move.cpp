void people_move()	//�Ѷȣ�3
{// ��ȡ��ǰ����λ��
	int current_x = people_pos[0];
	int current_y = people_pos[1];
// ���ݷ����ȷ���ƶ�����
	int dx = 0;
	int dy = 0;
	switch (dire) {
	case 72:dy = -1; break;//��
	case 80:dy = 1; break;//��
	case 75:dx = -1; break;//��
	case 77:dx = 1; break;//��
	default:return;//�Ƿ����������
	}
// ������λ��
	int new_x = current_x + dx;
	int new_y = current_y + dy;
// �߽���
	if (new_x < 0 || new_x >= 31 || new_y < 0 || new_y >= 31) {
		return;
	}
// ���Ŀ��λ������
	int target_cell = world[new_x][new_y];
// ����ǿյأ���ʼ����ƶ�
	if (target_cell == 0) {
    // ����ԭʼλ���������
		int old_pos[2] = { current_x,current_y };
	// �����ƶ�ֱ�������ϰ����߽�
		while (1) {
			//������λ��
			new_x += dx;
			new_y += dy;
			// ���߽�
			if (new_x < 0 || new_x >= 31 || new_y < 0 || new_y >= 31) {
				// �����߽磬����һ��
				new_x -= dx;
				new_y -= dy;
				break;
			}

			// �����λ���Ƿ���ƶ�
			if (world[new_x][new_y] != 0) {
				// �����ϰ������һ��
				new_x -= dx;
				new_y -= dy;
				break;
			}
         }
	// ��������λ��
		world[current_x][current_y] = 0;  // ���ԭλ��
		people_pos[0] = new_x;
		people_pos[1] = new_y;
		world[new_x][new_y] = 2;          // ������λ��
	// ����people_view������ʾ
		people_view(old_pos);
	}
// ������ţ�ֱ���ƶ�
	else if (target_cell == 3) {
	// �����λ��
		int old_pos[2] = { current_x, current_y };
		world[current_x][current_y] = 0;
		people_pos[0] = new_x;
		people_pos[1] = new_y;
		world[new_x][new_y] = 2;
	// ����people_view������ʾ
		people_view(old_pos);
	}
// ����Ǵ̻�ǽ�����ƶ�
	else {
		return;
	}
	// �ƶ���ɺ�����Ϸ״̬
	after_move_check();
}
