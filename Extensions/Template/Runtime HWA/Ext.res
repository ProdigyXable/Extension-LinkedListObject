        ��  ��                  �      �� ��     0 	        �4   V S _ V E R S I O N _ I N F O     ���                                           S t r i n g F i l e I n f o   �   0 4 0 9 0 4 e 4   4 
  C o m p a n y N a m e     C l i c k t e a m   @   F i l e D e s c r i p t i o n     E d i f   O b j e c t   *   F i l e V e r s i o n     2 . 0 0     0   I n t e r n a l N a m e   E d i f E x t   Z   L e g a l C o p y r i g h t   C o p y r i g h t   �   2 0 1 2   C l i c k t e a m     @   O r i g i n a l F i l e n a m e   E d i f E x t . m f x   :   P r o d u c t V e r s i o n   1 ,   0 ,   0 ,   1     2 	  S p e c i a l B u i l d   0 0 0 0 0 0 0 1     D    V a r F i l e I n f o     $    T r a n s l a t i o n     	�       ��
 ���     0 	        %Y�  (   E D I F   ��f       0 	        {
    "About": {
        "Name": "Xable Linked List Object",
        "Author": "Samuel Benton",
        "Copyright": "Copyright � 2014 Xable Enterprises",
        "Comment": "This extension allows the easy implementation of non-circular linked lists and linked list structures, such as stacks and queues, within MMFusion.\n\n**Note**\n Nodes currently support only integer data values.",
        "URL": "http://www.xable.us",
        "Help": "http://www.xable.us",
        "Identifier": "PXLL"
    },
    "ActionMenu": 
	[
		["Node Insertion",
		
			[4,"Add Node to Beginning of List"],
			[0,"Add Node to End of List"],
			"Separator",
			[5,"Insert Node at node index"],
		],

		["Node Deletion",
			[1,"Remove Head/First Node"],
			[2,"Remove Tail/Last Node"],
			"Separator",
			[3,"Remove Node via node index"],
			"Separator",
			[6, "Remove Multiple Nodes"],
		],

		["Node Manipulation",
			[7,"Swap Nodes"],
			[8,"Reverse Entire List"],
			[9,"Reverse Subsection of List"],
		],
    ],

    "ConditionMenu": 
	[
		["Node-based",
			[1, "Node just added?"],
			[2, "Node just removed?"],
		],

		["List-based",
			[0, "Is list empty?"],
			[3, "List just cleared?"],
		],
		
		["Errors",
			[4,"Index Bound Error"],
		],
		"Separator",
	],

    "ExpressionMenu": 
	[
		["Node Data",
			[2,"Get Data from Head/First Node"],
			[0,"Get Data from Tail/Last Node"],
			"Separator",
			[3,"Get Data from Node via node index"],
		],

		["List Data",
			[1, "Get List Size"],
		],
			"Separator",
    ],
    "Actions": 
	[
        {"Title": "Add Node to list end with data %0",
            "Parameters": 
			[
				["Integer","Data"]
            ]
        },
		{"Title": "Remove Head/Front Node",
        },
		{"Title": "Remove Tail/End Node",
        },
		{"Title": "Remove Node with index %0",
            "Parameters": 
			[
				["Integer","Node Index"]
            ]
        },
		{"Title": "Add Node to list front with data %0",
            "Parameters": 
			[
				["Integer","Data"]
            ]
        },
		{"Title": "Insert Node to index %0 with data %1",
            "Parameters": 
			[
				["Integer","Node Index"],
				["Integer","Data"]
            ]
        },
		{"Title": "Remove %1 consecutive node(s) starting with node %0",
            "Parameters": 
			[
				["Integer","Initial Node Index"],
				["Integer","Number of Nodes to Delete"]
            ]
        },
		{"Title": "Swap node %0 with node %1",
            "Parameters": 
			[
				["Integer","Node Index A"],
				["Integer","Node Index B"]
            ]
        },
		{"Title": "Reverse List",
        },
		{"Title": "Reverse Subsection of List from index %0 to %1",
            "Parameters": 
			[
				["Integer","Node Index A"],
				["Integer","Node Index B"]
            ]
        },
    ],
    "Conditions": 
	[
		{
			"Title": "%o : Is list empty",
            "Parameters":
			[
            ],
            "Triggered": false
        },
		{
			"Title": "%o : Node just added",
            "Parameters":
			[
            ],
            "Triggered": true
        },
		{
			"Title": "%o : Node just removed",
            "Parameters":
			[
            ],
            "Triggered": true
        },
		{
			"Title": "%o : List just cleared",
            "Parameters":
			[
            ],
            "Triggered": true
		},        
		{
			"Title": "%o : Index boundary error",
            "Parameters":
			[
            ],
            "Triggered": true
        },
    ],
    "Expressions": 
	[
        {
			"Title": "GetEndData(",
			 "Returns": "Integer",
        },
		{
			"Title": "ListSize(",
			 "Returns": "Integer",
        },
		{
			"Title": "GetStartData(",
			 "Returns": "Integer",
        },
		{
			"Title": "GetData(",
			"Returns": "Integer",
			"Parameters": 
			[
				["Integer","Node Index"],
            ]
			 
        },
    ]
}  &       �� ��     0	           M F 2                               