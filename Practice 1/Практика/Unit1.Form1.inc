procedure InitializeComponent;
    begin
        self.button1 := new System.Windows.Forms.Button();
        self.button2 := new System.Windows.Forms.Button();
        self.button3 := new System.Windows.Forms.Button();
        self.button4 := new System.Windows.Forms.Button();
        self.SuspendLayout();
        // 
        // button1
        // 
        self.button1.Location := new System.Drawing.Point(51, 26);
        self.button1.Name := 'button1';
        self.button1.Size := new System.Drawing.Size(196, 54);
        self.button1.TabIndex := 0;
        self.button1.Text := 'Добавить данные';
        self.button1.UseVisualStyleBackColor := true;
        self.button1.Click += button1_Click;
        // 
        // button2
        // 
        self.button2.Location := new System.Drawing.Point(51, 112);
        self.button2.Name := 'button2';
        self.button2.Size := new System.Drawing.Size(196, 54);
        self.button2.TabIndex := 1;
        self.button2.Text := 'Удалить данные';
        self.button2.UseVisualStyleBackColor := true;
        self.button2.Click += button2_Click;
        // 
        // button3
        // 
        self.button3.Location := new System.Drawing.Point(51, 201);
        self.button3.Name := 'button3';
        self.button3.Size := new System.Drawing.Size(196, 54);
        self.button3.TabIndex := 2;
        self.button3.Text := 'Показать данные';
        self.button3.UseVisualStyleBackColor := true;
        self.button3.Click += button3_Click;
        // 
        // button4
        // 
        self.button4.Location := new System.Drawing.Point(51, 291);
        self.button4.Name := 'button4';
        self.button4.Size := new System.Drawing.Size(196, 54);
        self.button4.TabIndex := 3;
        self.button4.Text := 'Выход';
        self.button4.UseVisualStyleBackColor := true;
        self.button4.Click += button4_Click;
        // 
        // Form1
        // 
        self.ClientSize := new System.Drawing.Size(308, 377);
        self.Controls.Add(self.button4);
        self.Controls.Add(self.button3);
        self.Controls.Add(self.button2);
        self.Controls.Add(self.button1);
        self.Name := 'Form1';
        self.Text := 'Главное меню';
        self.ResumeLayout(false);
    end;
